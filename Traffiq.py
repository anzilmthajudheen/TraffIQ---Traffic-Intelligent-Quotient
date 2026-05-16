import cv2
import serial
import time

# Serial Connection
ser = serial.Serial('COM7', 115200)
time.sleep(2)

# Camera
cap = cv2.VideoCapture(0)

# Variables
current_lane = None
last_switch_time = time.time()

MIN_GREEN_TIME = 5      # seconds
YELLOW_TIME = 2         # seconds

# -----------------------------
# Detect Traffic Density
# -----------------------------
def detect_density(lane):
    gray = cv2.cvtColor(lane, cv2.COLOR_BGR2GRAY)

    # Blur to reduce noise
    blur = cv2.GaussianBlur(gray, (5, 5), 0)

    # Binary Threshold
    _, th = cv2.threshold(blur, 120, 255, cv2.THRESH_BINARY_INV)

    density = cv2.countNonZero(th)

    return density

# -----------------------------
# Emergency Vehicle Detection
# -----------------------------
def detect_emergency(lane):

    # Detect bright white ambulance region
    mask = cv2.inRange(lane, (200, 200, 200), (255, 255, 255))

    white_pixels = cv2.countNonZero(mask)

    return white_pixels > 6000

# -----------------------------
# Send Signal Command
# -----------------------------
def send_signal(command):

    global current_lane

    if current_lane != command:
        ser.write((command + '\n').encode())
        current_lane = command

        print("Signal Sent:", command)

# -----------------------------
# Main Loop
# -----------------------------
while True:

    ret, frame = cap.read()

    if not ret:
        break

    h, w, _ = frame.shape

    # Divide Frame into 3 Lanes
    lane1 = frame[:, :w//3]
    lane2 = frame[:, w//3:2*w//3]
    lane3 = frame[:, 2*w//3:]

    # -----------------------------
    # Emergency Handling
    # -----------------------------
    if detect_emergency(lane1):

        send_signal("E1")
        print("🚑 Emergency in Lane 1")

    elif detect_emergency(lane2):

        send_signal("E2")
        print("🚑 Emergency in Lane 2")

    elif detect_emergency(lane3):

        send_signal("E3")
        print("🚑 Emergency in Lane 3")

    else:

        # Density Calculation
        c1 = detect_density(lane1)
        c2 = detect_density(lane2)
        c3 = detect_density(lane3)

        print(f"Lane1: {c1} | Lane2: {c2} | Lane3: {c3}")

        # Find Highest Density Lane
        max_lane = max(
            [("L1", c1), ("L2", c2), ("L3", c3)],
            key=lambda x: x[1]
        )[0]

        # Prevent Frequent Switching
        current_time = time.time()

        if current_time - last_switch_time > MIN_GREEN_TIME:

            send_signal(max_lane)

            last_switch_time = current_time

    # -----------------------------
    # Display Windows
    # -----------------------------
    cv2.imshow("Lane 1", lane1)
    cv2.imshow("Lane 2", lane2)
    cv2.imshow("Lane 3", lane3)

    # ESC to Exit
    if cv2.waitKey(1) == 27:
        break

# Cleanup
cap.release()
cv2.destroyAllWindows()
ser.close()
