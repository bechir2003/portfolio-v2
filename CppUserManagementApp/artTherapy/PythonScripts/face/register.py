import os.path
import datetime
import pickle
import sys

import tkinter as tk
import cv2
from PIL import Image, ImageTk
import face_recognition

import util
from test import test


class App:
    def __init__(self):
        self.main_window = tk.Tk()
        self.main_window.geometry("1200x520+350+100")

        self.register_new_user_button_main_window = util.get_button(self.main_window, 'register new user', 'gray',
                                                                    self.register_new_user, fg='black')
        self.register_new_user_button_main_window.place(x=750, y=400)

        self.webcam_label = util.get_img_label(self.main_window)
        self.webcam_label.place(x=10, y=0, width=700, height=500)

        self.add_webcam(self.webcam_label)

        self.db_dir = r''
        if not os.path.exists(self.db_dir):
            os.mkdir(self.db_dir)

        self.log_path = './log.txt'

    def add_webcam(self, label):
        if 'cap' not in self.__dict__:
            droidcam_url = f"http://x.x.x.x:4747/video"
            self.cap = cv2.VideoCapture(droidcam_url)

        self._label = label
        self.process_webcam()

    def process_webcam(self):
        ret, frame = self.cap.read()

        self.most_recent_capture_arr = frame
        img_ = cv2.cvtColor(self.most_recent_capture_arr, cv2.COLOR_BGR2RGB)
        self.most_recent_capture_pil = Image.fromarray(img_)
        imgtk = ImageTk.PhotoImage(image=self.most_recent_capture_pil)
        self._label.imgtk = imgtk
        self._label.configure(image=imgtk)

        self._label.after(20, self.process_webcam)

    def register_new_user(self):
        self.register_new_user_window = tk.Toplevel(self.main_window)
        self.register_new_user_window.geometry("1200x520+370+120")

        self.accept_button_register_new_user_window = util.get_button(self.register_new_user_window, 'Accept', 'green', self.accept_register_new_user)
        self.accept_button_register_new_user_window.place(x=750, y=300)

        self.try_again_button_register_new_user_window = util.get_button(self.register_new_user_window, 'Try again', 'red', self.try_again_register_new_user)
        self.try_again_button_register_new_user_window.place(x=750, y=400)

        self.capture_label = util.get_img_label(self.register_new_user_window)
        self.capture_label.place(x=10, y=0, width=700, height=500)

        self.add_img_to_label(self.capture_label)

    def try_again_register_new_user(self):
        self.register_new_user_window.destroy()

    def add_img_to_label(self, label):
        imgtk = ImageTk.PhotoImage(image=self.most_recent_capture_pil)
        label.imgtk = imgtk
        label.configure(image=imgtk)

        self.register_new_user_capture = self.most_recent_capture_arr.copy()

    def start(self):
        self.main_window.mainloop()

    def accept_register_new_user(self):
        name = sys.argv[1] 

        # Face recognition
        face_encodings = face_recognition.face_encodings(self.register_new_user_capture)

        if len(face_encodings) == 0:
            util.msg_box('Error!', 'No face detected in the image. Please try again.')
            return

        embeddings = face_encodings[0]

        # Get a unique filename
        unique_filename = self.get_unique_filename(os.path.join(self.db_dir, '{}.pickle'.format(name)))

        # Save the face embeddings with the unique filename
        with open(unique_filename, 'wb') as file:
            pickle.dump(embeddings, file)

        util.msg_box('Success!', 'User was registered successfully !')

        self.register_new_user_window.destroy()
        sys.exit(0)

    def get_unique_filename(self, save_path):
        # Extract directory and base filename
        directory, filename = os.path.split(save_path)
        filename_no_ext, ext = os.path.splitext(filename)

        # Check if the file already exists
        if os.path.exists(save_path):
            # If the file exists, find a unique filename
            i = 1
            while True:
                new_filename = f"{filename_no_ext}_{i}{ext}"
                new_save_path = os.path.join(directory, new_filename)
                if not os.path.exists(new_save_path):
                    return new_save_path
                i += 1
        else:
            # If the file doesn't exist, return the original save path
            return save_path


if __name__ == "__main__":
    app = App()
    app.start()
