import speech_recognition as sr

def reconnaissance():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        r.adjust_for_ambient_noise(source)
        r.pause_threshold = 0.7
        print("Dites quelque chose...")
        audio = r.listen(source)
        try:
            print("Reconnaissance en cours...")
            texte = r.recognize_google(audio, language="fr-FR")
            print("Texte reconnu:\n", texte)  
            return texte
        except sr.UnknownValueError:
            print("Impossible de comprendre l'audio.")
            return None

def ecrire_dans_fichier(texte, nom_fichier= r"D:\ESPRIT\c++\Projet\ProjetC++\Gestion_Charite\reconnaissance.txt"):
    try:
        with open(nom_fichier, "a+") as fichier:
            fichier.write(texte + "\n")
    except Exception as e:
        print("An error occurred while writing to the file:", e)

def main():
    while True:
        entree = reconnaissance()
        if entree  is not None:
            if "arrêt" in entree.lower():
                print("Arrêt de l'assistant.")
                break
            ecrire_dans_fichier(entree)

if __name__ == "__main__":
    main()
