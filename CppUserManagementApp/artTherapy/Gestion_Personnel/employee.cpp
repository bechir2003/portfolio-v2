#include "employee.h"
#include <QSqlQuery>
#include "ui_mainwindow.h"

//BEGIN CONSTRUCTOR1
employee::employee(){
    Id_Emp=0;
    Nom="";
    Prenom="";
    Email="";
    NumTel=0;
    Adresse="";
    Sexe="";
    Mdp="";
    Salaire=0;
    CIN="";
}
//END CONSTRUCTOR1

//BEGIN CONSTRUCTOR2
employee::employee(int Id_Emp,QString Nom,QString Prenom,QDate Age,QString Email,QString Role,int NumTel,QString Adresse,QString Sexe,QString Mdp,float Salaire,QString CIN,QDate DateEmb)
{
    this->Id_Emp=Id_Emp;
    this->Nom=Nom;
    this->Prenom=Prenom;
    this->Age=Age;
    this->Email=Email;
    this->NumTel=NumTel;
    this->Adresse=Adresse;
    this->Sexe=Sexe;
    this->Mdp=Mdp;
    this->Salaire=Salaire;
    this->Role=Role;
    this->DateEmb=DateEmb;
    this->CIN=CIN;

}
//END CONSTRUCTOR2

//BEGIN DESTRUCTOR
employee::~employee()
{
    // Destructor implementation (if needed)
}
//END DESTRUCTOR

//BEGIN afficher_Employees
QSqlQueryModel* employee::afficher_Employees() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id_emp,CIN,nom, prenom,TO_CHAR(datenaiss, 'YYYY-MM-DD' ) as datenaiss,TO_CHAR(dateEmb, 'YYYY-MM-DD' ) as dateEmb,email,sexe, adresse, numtel, salaire,Role FROM employee;");
    return model;
}
//END afficher_Employees

//BEGIN Ajouter_Employee
bool employee::Ajouter_Employee(){
    QSqlQuery query;

    query.prepare("INSERT INTO EMPLOYEE VALUES (NULL, :nom, :prenom, :age, :email, :numtel, :adresse, :sexe, :salaire, :mdp,:role,:CIN,:dateEmb,NULL)");
    query.bindValue(":nom",getNom());
    query.bindValue(":prenom", getPrenom());
    query.bindValue(":age", QVariant::fromValue<QDate>(getAge()));
    query.bindValue(":email", getEmail());
    query.bindValue(":numtel", getNumTel());
    query.bindValue(":adresse", getAdresse());
    query.bindValue(":sexe", getSexe());
    query.bindValue(":mdp", getMdp());
    query.bindValue(":salaire", QVariant(static_cast<double>(getSalaire())));
    query.bindValue(":role", getRole());
    query.bindValue(":CIN", getCIN());
    query.bindValue(":dateEmb", QVariant::fromValue<QDate>(QDate::currentDate()));

    bool success= query.exec();
    /*if(success){
        QSqlQuery query1;
        query1.prepare("SELECT ID_EMP FROM employee WHERE cin = :cin");
        query1.bindValue(":cin", getCIN()); // Assuming getCIN() returns the CIN value
        query1.exec();
        int id=0;
        if(query1.next()){    
            id = query1.value(0).toInt(); // Retrieve the ID from the query result
            // Now you can use the 'id' variable as needed
        }
        historique("ajoute","",id);
    }*/
    return success;
}
//END Ajouter_Employee

//BEGIN Effacer_Employee
bool employee::Effacer_Employee(int id){
    QSqlQuery query;
    historique("supprime","",id);
    query.prepare("delete from employee where ID_EMP=:id");
    query.bindValue(":id", id);
    return query.exec();
}
//END Effacer_Employee

//BEGIN Effacer_Employee_CIN
bool employee::Effacer_Employee_CIN(int CIN){
    QSqlQuery query;

    query.prepare("delete from employee where CIN=:cin");
    query.bindValue(":cin", CIN);
    return query.exec();
}
//END Effacer_Employee_CIN

//BEGIN Modifier_Employee
bool employee::Modifier_Employee(QTableWidgetItem *item, QString columnHeader, int id_Emp) {
    QSqlQuery query;
    bool success = false;
    Gestion_Personnel G;
    QString queryText = "UPDATE employee SET " + columnHeader + " = :value WHERE ID_EMP = :id ;";

    if (columnHeader == "DATENAISS" || columnHeader == "DATEEMB") {
        QDate value = QDate::fromString(item->text(), "yyyy-MM-dd");
        if(columnHeader == "DATENAISS"){
            if(!G.valideDateNaiss(value) || !G.valideDate(value)){
                QMessageBox::critical(nullptr, "Erreur", "Date Naiss invalide!!");
                return  false;
            }
        }
        else{
            if(!G.valideDate(value)){
                QMessageBox::critical(nullptr, "Erreur", "DateEmb invalide!!");
                return  false;
            }
        }

        query.prepare(queryText);
        query.bindValue(":value", value);
        query.bindValue(":id", id_Emp);
    }
    else if (columnHeader == "SALAIRE") {
        float value = item->text().toFloat();
        query.prepare(queryText);
        query.bindValue(":value", QVariant(static_cast<double>(value)));
        query.bindValue(":id", id_Emp);
    }
    else if (columnHeader == "ROLE"){
        QString value = item->text();
        if(value != "Employee" && value != "Gestion_Personnels" && value != "Gestion_Oeuvres" && value != "Gestion_Participants" && value != "Gestion_Charites" && value != "Gestion_Evenements"){
            QMessageBox::critical(nullptr, "Erreur", "ROLE invalide!!");
            return  false;
        }
        query.prepare(queryText);
        query.bindValue(":value", value);
        query.bindValue(":id", id_Emp);
    }
    else if (columnHeader == "SEXE"){
        QString value = item->text();
        if(value != "H" && value != "F"){
            QMessageBox::critical(nullptr, "Erreur", "SEXE invalide!!");
            return  false;
        }
        query.prepare(queryText);
        query.bindValue(":value", value);
        query.bindValue(":id", id_Emp);
    }
    else if (columnHeader == "CIN"){
        QString value = item->text();
        if(!G.valideCIN(value) || Existance_Employee_CIN(value)){
            QMessageBox::critical(nullptr, "Erreur", "CIN invalide ou existe!!");
            return  false;
        }
        query.prepare(queryText);
        query.bindValue(":value", value);
        query.bindValue(":id", id_Emp);
    }
    else if (columnHeader == "EMAIL"){
        QString value = item->text();
        if(!G.valideEmail(value) || Existance_Employee(value)){
            QMessageBox::critical(nullptr, "Erreur", "EMAIL invalide ou existe!!");
            return  false;
        }
        query.prepare(queryText);
        query.bindValue(":value", value);
        query.bindValue(":id", id_Emp);
    }
    else if (columnHeader == "NUMTEL"){
        QString value = item->text();
        if(!G.valideTEL(value)){
            QMessageBox::critical(nullptr, "Erreur", "NUMTEL invalide!!");
            return  false;
        }
        query.prepare(queryText);
        query.bindValue(":value", value);
        query.bindValue(":id", id_Emp);
    }
    else{
        QString value = item->text();
        if(value.length()<3){
            QMessageBox::critical(nullptr, "Erreur", "Nom ou Prenom ou Adresse est invalide!!");
            return  false;
        }
        query.prepare(queryText);
        query.bindValue(":value", value);
        query.bindValue(":id", id_Emp);
    }

    if (query.exec()) {
        qDebug() << "Query executed successfully.";
        success = true;
    }
    historique("modifie",columnHeader,id_Emp);
    return success;
}

//END Modifier_Employee

//BEGIN Modifier_Employee
bool employee::Modifier_Employee(int id,QString attribute,QString newValue){
    QSqlQuery query;

    query.prepare("UPDATE employee SET " + attribute + " = :newValue WHERE id_emp = :id ;");

    query.bindValue(":newValue",newValue);
    query.bindValue(":id",id);

    historique("modifie",attribute,id);

    return query.exec();

}
//END Modifier_Employee

//BEGIN Modifier_Employee
void employee::historique(QString value,QString value2,int id_Emp){
    employee E;
    E = E.afficher_Employee(id_Emp);
    ofstream file("historic.txt", std::ios::app);
    if (file.is_open()) {
        time_t currentTime = std::time(nullptr);
        struct tm* localTime = std::localtime(&currentTime);

        file << "Un employee " << value.toStdString() << " le: " << asctime(localTime)
             << "Nom: " << E.getNom().toStdString() << "\n"
             << "Prenom: " << E.getPrenom().toStdString() << "\n"
             << "Dtae de naissance: " << E.getAge().toString("yyyy-MM-dd").toStdString() << "\n"
             << "Email: " << E.getEmail().toStdString() << "\n"
             << "NumTel: " << E.getNumTel() << "\n"
             << "Addresse: " << E.getAdresse().toStdString() << "\n";
        if(value=="modifie"){
            file<< "Attribus modifie: " << value2.toStdString()  << "\n\n";
        }
        else{
            file<< "\n";
        }

        file.close();
    }
}
//END historique

//BEGIN afficher_Employee
employee employee::afficher_Employee(int id) {
    QSqlQueryModel model;
    QDate date;
    employee E(id, "", "", date, "", "", 0, "", "", "", 0, "", date);
    QSqlQuery query;

    query.prepare("SELECT * FROM employee WHERE id_emp = :id or CIN=:id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        E.setNom(query.value(1).toString());
        E.setPrenom(query.value(2).toString());
        E.setAge(query.value(3).toDate());
        E.setEmail(query.value(4).toString());
        E.setNumTel(query.value(5).toInt());
        E.setAdresse(query.value(6).toString());
    }

    return E;
}

//END afficher_Employee

//BEGIN Existance_Employee
bool employee::Existance_Employee(QString email){
    QSqlQuery query;
    query.prepare("select * from employee where email=:email");
    query.bindValue(":email",email);
    query.exec();
    return query.next();
}
//END Existance_Employee


//BEGIN Existance_Employee_CIN
bool employee::Existance_Employee_CIN(QString CIN){
    QSqlQuery query;
    query.prepare("select * from employee where CIN=:CIN");
    query.bindValue(":CIN",CIN);
    query.exec();
    return query.next();
}
//END Existance_Employee_CIN

//BEGIN Existance_Employee_ID
bool employee::Existance_Employee_ID(int id){
    QSqlQuery query;
    query.prepare("select * from employee where id_emp=:id");
    query.bindValue(":id",id);
    query.exec();
    return query.next();
}
//END Existance_Employee_ID
