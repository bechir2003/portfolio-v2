#include "oeuvre.h"
#include "dialog.h"
#include <fstream>
#include <ctime>

Oeuvre::Oeuvre()
{

}

Oeuvre::Oeuvre(int id_o,QString nom_artiste,QString type,float prix,QString etat,int id_e)
{
    this->Id_o=id_o;
    this->Nom_artiste=nom_artiste;
    this->type=type;
    this->prix=prix;
    this->etat=etat;
    this->id_e=id_e;
}


QSqlQueryModel* Oeuvre::afficher_Oeuvre() {
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM Oeuvre;");

    return model;

}

bool Oeuvre::Ajouter_Oeuvre(){
    QSqlQuery query;

    query.prepare("INSERT INTO Oeuvre VALUES (NULL, :nomA, :type, :prix, 'disponible', :event)");
    query.bindValue(":nomA",Nom_artiste);
    query.bindValue(":Etat", etat);
    query.bindValue(":type", type);
    query.bindValue(":prix", QVariant(static_cast<double>(prix)));
    query.bindValue(":event", id_e);

    bool queryExecuted = query.exec();
    if (queryExecuted) {
        // Append information to historic.txt with current date
        std::ofstream file("historic.txt", std::ios::app);
        std::ofstream file1("Gestion_Oeuvre/historic.txt", std::ios::app);
        if (file.is_open() && file1.is_open()) {
            std::time_t currentTime = std::time(nullptr);
            struct std::tm* localTime = std::localtime(&currentTime);
            Dialog D;
            QString event=D.get_NomEvent(id_e);
            file << "New oeuvre added on: " << std::asctime(localTime)
                 << "Nom artiste: " << Nom_artiste.toStdString() << "\n" // Convert QString to std::string
                 << "Type: " << type.toStdString() << "\n" // Convert QString to std::string
                 << "Prix: " << prix << "\n"
                 << "Event: " << event.toStdString() << "\n\n";

            file.close();

            file1 << "New oeuvre added on: " << std::asctime(localTime)
                 << "Nom artiste: " << Nom_artiste.toStdString() << "\n" // Convert QString to std::string
                 << "Type: " << type.toStdString() << "\n" // Convert QString to std::string
                 << "Prix: " << prix << "\n"
                 << "Event: " << event.toStdString() << "\n\n";

            file1.close();
            return true; // Indicate success
        } else {
            // Failed to open file
            // Handle error
            return  false; // Indicate failure
        }
    }
    else {
        return false; // Indicate failure
    }
}

bool Oeuvre::Effacer_Oeuvre(int id){
    QSqlQuery query;
    QSqlQuery query1;

    query.prepare("select * from Oeuvre where id_o=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) { // Check if the query executed successfully and if there is at least one result
        QString Nom_artiste = query.value(1).toString(); // Assuming Nom_artiste is the second column (index 1)
        QString type = query.value(2).toString(); // Assuming type is the third column (index 2)
        double prix = query.value(3).toDouble(); // Assuming prix is the fourth column (index 3)
        int id_e = query.value(5).toInt(); // Assuming id_e is the fifth column (index 4)

        std::ofstream file("historic.txt", std::ios::app);
        std::ofstream file1("Gestion_Oeuvre/historic.txt", std::ios::app);
        if (file.is_open() && file1.is_open()) {
            std::time_t currentTime = std::time(nullptr);
            struct std::tm* localTime = std::localtime(&currentTime);
            Dialog D;
            QString event=D.get_NomEvent(id_e);
            file << "new oeuvre deleted on: " << std::asctime(localTime)
            << "Nom artiste: " << Nom_artiste.toStdString() << "\n"
            << "Type: " << type.toStdString() << "\n"
            << "Prix: " << prix << "\n"
            << "Event: " << event.toStdString() << "\n\n";
            file.close();

            file1 << "new oeuvre deleted on: " << std::asctime(localTime)
            << "Nom artiste: " << Nom_artiste.toStdString() << "\n"
            << "Type: " << type.toStdString() << "\n"
            << "Prix: " << prix << "\n"
            << "Event: " << event.toStdString() << "\n\n";
            file1.close();
        }
    }
    query1.prepare("delete from Oeuvre where id_o=:id");
    query1.bindValue(":id", id);
    return  query1.exec();
}

bool Oeuvre::Modifier_Oeuvre(Oeuvre O,int id) {
    QSqlQuery query;

    query.prepare("UPDATE Oeuvre SET NOM_ARTISTE=:nomA,ETAT=:Etat, TYPE=:type, PRIX=:prix, id_event=:event WHERE id_o=:id");
    query.bindValue(":nomA",O.getNomArtiste());
    query.bindValue(":Etat", O.getEtat());
    query.bindValue(":type", O.getType());
    query.bindValue(":prix", QVariant(static_cast<double>(O.getPrix())));
    query.bindValue(":event", O.getEvent());
    query.bindValue(":id", id);

    bool queryExecuted = query.exec();
    if (queryExecuted) {

        std::ofstream file("historic.txt", std::ios::app);
        std::ofstream file1("Gestion_Oeuvre/historic.txt", std::ios::app);
        if (file.is_open() && file1.is_open()) {
            std::time_t currentTime = std::time(nullptr);
            struct std::tm* localTime = std::localtime(&currentTime);
            Dialog D;
            QString event=D.get_NomEvent(O.getEvent());
            file << "New oeuvre modifed on: " << std::asctime(localTime)
                 << "Nom artiste: " << O.getNomArtiste().toStdString() << "\n" // Convert QString to std::string
                 << "Type: " << O.getType().toStdString() << "\n" // Convert QString to std::string
                 << "Prix: " << O.getPrix() << "\n"
                 << "Event: " << event.toStdString() << "\n\n";

            file.close();

            file1 << "New oeuvre modifed on: " << std::asctime(localTime)
                 << "Nom artiste: " << O.getNomArtiste().toStdString() << "\n" // Convert QString to std::string
                 << "Type: " << O.getType().toStdString() << "\n" // Convert QString to std::string
                 << "Prix: " << O.getPrix() << "\n"
                 << "Event: " << event.toStdString() << "\n\n";

            file1.close();
        }
    }
    return queryExecuted;
}
