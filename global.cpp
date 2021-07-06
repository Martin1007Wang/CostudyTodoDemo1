//#include "global.h"
//#include <QSqlDatabase>

//Global::Global(){};

//QSqlDatabase Global::db = QSqlDatabase::addDatabase("QMYSQL");

//bool Global::isPwd(const QString &pwd){
//        bool back = true;
//        QByteArray byte = pwd.toUtf8();
//        for(int i = 0; i < pwd.size(); i++){
//            int ascii =  int(byte.at(i));
//            if((65<=ascii && ascii<=90) || (48<=ascii && ascii<=57) || (97<=ascii && ascii<=122)){
//                back = true;
//            }
//            else{
//                back = false;
//                break;
//            }
//        }
//        return back;
//}

//bool Global::isUid(const QString &uid){
//    bool back = true;
//    QByteArray byte = uid.toUtf8();
//    for(int i = 0; i < uid.size(); i++){
//        int ascii =  int(byte.at(i));
//        if((65<=ascii && ascii<=90) || (48<=ascii && ascii<=57) || (97<=ascii && ascii<=122) || (ascii<0)){
//            back = true;
//        }
//        else{
//            back = false;
//            break;
//        }
//    }
//    return back;
//}

//bool Global::isEmail(const QString &email){
//    bool back = true;
//    QByteArray byte = email.toUtf8();
//    for(int i = 0; i < email.size(); i++){
//        int ascii =  int(byte.at(i));
//        if((ascii == 64) && (i != 0) && (i != email.size() - 1)){
//            back = true;
//            break;
//        }
//        else{
//            back = false;
//        }
//    }
//    return back;
//}
