#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class Participant
{
public:
    Participant();
    Participant(int, QString, QString, QDate date_naiss, QString, int, QString, QString);
    bool ajouter_P();
    static QSqlQueryModel* afficher();
    static bool supprimer(int CIN);
    bool ModifierParticipant(Participant ,int);


       QString get_nom();
       QString get_prenom();
       QString get_email();
       QString get_adresse();
       QString get_sexe();
       int  get_CIN();
       int  get_numTel();
       QDate get_date();

          void set_nom(QString nom);
          void set_prenom(QString prenom);
          void set_email(QString email);
          void set_adresse(QString adresse);
          void set_sexe(QString sexe);
          void set_CIN(int CIN);
          void  set_numTel(int numTel);
          void set_date(QDate date);
private:
    int CIN,num_tel;
    QString nom,prenom,adresse,sexe,email;
    QDate date_naiss;

};

#endif // PARTICIPANT_H
