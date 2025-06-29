import sys
from twilio.rest import Client

# Vos identifiants Twilio
account_sid = 'AC059109f67c3690ca9d7618c28f7e7c5f'
auth_token = '5f2b51dfa21e3d6ffcc219c4a2e7a7fa'

# Initialiser le client Twilio
client = Client(account_sid, auth_token)

# Numéro de téléphone de l'expéditeur (votre numéro Twilio)
from_number = '+12566394020'

# Numéro de téléphone du destinataire
to_number = sys.argv[1]
montant = sys.argv[2]
destination =sys.argv[3]


# Message à envoyer
message_body = f'Chers {destination} , un montant de {montant}dt est transféré d"apres notre organisation VIRTUSO VISION '

try:
    # Envoyer le message
    message = client.messages.create(
        body=message_body,
        from_=from_number,
        to=to_number
    )
    print("Message envoyé avec succès. ID du message:", message.sid)

except Exception as e:
    print("Une erreur s'est produite lors de l'envoi du message :", e)
