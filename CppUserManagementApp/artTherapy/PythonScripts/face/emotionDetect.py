
from fer import FER
import cv2

def detectEmotion(img):
    # Create an instance of FER with MTCNN face detection
    emotion_detector = FER(mtcnn=True)

    # Resize the input image
    img_resized = cv2.resize(img, (600, 600))

    # Detect emotions in the resized image
    emotions = emotion_detector.detect_emotions(img_resized)
    print(emotions)

    # Get the top emotion and its score
    top_emotion, emotion_score = emotion_detector.top_emotion(img_resized)
    return top_emotion, emotion_score

# Example usage:
# img = cv2.imread('example_image.jpg')
# top_emotion, emotion_score = detectEmotion(img)
# print("Top Emotion:", top_emotion, "Score:", emotion_score)
