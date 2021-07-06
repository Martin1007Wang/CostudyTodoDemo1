//#include "api_sql.h"

//bool connect(){
//    Global::db.setHostName("127.0.0.1");
//    Global::db.setPort(3306);
//    Global::db.setDatabaseName("costudy");
//    Global::db.setUserName("root");
//    Global::db.setPassword("20020610");
//    if(Global::db.open()){
//        qDebug()<<"SQL has been connected.";
//        return true;
//    }
//    else{
//        qDebug()<<Global::db.lastError().text();
//        return false;
//    }
//}

//bool createTable(const QString &tableName,const QStringList &tableHeadList){
//        if(tableHeadList.length()<=0){
//            qDebug()<<"ERROR:the first parameter must be an integer greater than 0";
//            return false;
//        }
//        else if(tableHeadList.length() % 2 != 0){
//            qDebug()<<"ERROR:cannot match field and type";
//            return false;
//        }
//        QSqlQuery query(Global::db);
//        QString sql = QString("CREATE TABLE IF NOT EXISTS %1 (").arg(tableName);
//        for(int i = 0;i<tableHeadList.length();i+=2){
//            sql.append(tableHeadList[i]);
//            sql.append(" ");
//            sql.append(tableHeadList[i+1]);
//            sql.append(",");
//        }
//        sql.remove(sql.length()-1,1);
//        sql+=")ENGINE=InnoDB DEFAULT CHARSET=utf8;";
//        if(query.exec(sql)){
//            qDebug()<<tableName<<"was created.";
//            return true;
//        }
//        else{
//             qDebug()<<query.lastError().text();
//             return false;
//        }
//}

//bool insert(const QString &tableName,const QString &field,const QString &value){
//    QSqlQuery query(Global::db);
//    QString sql = QString("INSERT INTO %1 (%2) VALUES ('%3');").arg(tableName,field,value);
//    if(query.exec(sql)){
//        qDebug()<<value<<"was inserted into"<<field<<"in"<<tableName;
//        return true;
//    }
//    else{
//        qDebug()<<query.lastError().text();
//        return false;
//    }
//}
//bool insert(const QString &tableName,const QString &field,const QDate &value){
//    QSqlQuery query(Global::db);
//    QString sql = QString("INSERT INTO %1 (%2) VALUES ('%3');").arg(tableName,field,value.toString());
//    if(query.exec(sql)){
//        qDebug()<<value<<"was inserted into"<<field<<"in"<<tableName;
//        return true;
//    }
//    else{
//        qDebug()<<query.lastError().text();
//        return false;
//    }
//}
//bool insert(const QString &tableName,const QString &field,const QTime &value){
//    QSqlQuery query(Global::db);
//    QString sql = QString("INSERT INTO %1 (%2) VALUES ('%3');").arg(tableName,field,value.toString());
//    if(query.exec(sql)){
//        qDebug()<<value<<"was inserted into"<<field<<"in"<<tableName;
//        return true;
//    }
//    else{
//        qDebug()<<query.lastError().text();
//        return false;
//    }
//}

//bool insertOne(const QString &tableName,const QStringList &fieldList,const QStringList &valueList){
//    if(fieldList.length() != valueList.length()){
//        qDebug()<<"ERROR:cannot match the field and value";
//        return false;
//    }
//    QSqlQuery query(Global::db);
//    QString sql = QString("INSERT INTO %1 (").arg(tableName);
//    for(int i = 0;i<fieldList.length();i++){
//        sql.append(fieldList[i]);
//        sql.append(",");
//    }
//    sql.remove(sql.length()-1,1);
//    sql+=") VALUES (";
//    for(int i = 0;i<valueList.length();i++){
//        sql.append("'");
//        sql.append(valueList[i]);
//        sql.append("',");
//    }
//    sql.remove(sql.length()-1,1);
//    sql+=");";
//    if(query.exec(sql)){
//        qDebug()<<valueList<<"was inserted into"<<fieldList<<"in"<<tableName;
//        return true;
//    }
//    else{
//        qDebug()<<query.lastError().text();
//        return false;
//    }
//}

//bool insertMany(const QString &tableName,const QStringList &fieldList,const QStringList &valueList){
//    if(valueList.length() % fieldList.length() != 0){
//        qDebug()<<"ERROR:cannot match the field and value";
//        return false;
//    }
//    bool back = false;
//    for(int i = 0;i<(valueList.length()/fieldList.length());i++){
//        QStringList list = valueList.mid(fieldList.length()*i,fieldList.length());
//        back = insertOne(tableName,fieldList,list);
//    }
//    return back;
//}

//bool addField(const QString &tableName,const QString &fieldName,const QString &fieldType,const bool &binary,const bool &null){
//    QSqlQuery query(Global::db);
//    QString sql = QString("ALTER TABLE %1 ADD %2 %3").arg(tableName,fieldName,fieldType);
//    if(binary){
//        sql+=" BINARY";
//    }
//    if(null){
//        sql+=";";
//    }
//    else{
//        sql+=" NOT NULL;";
//    }
//    if(query.exec(sql)){
//        qDebug()<<fieldName<<"was added of which fielyType ="<<fieldType<<"and NULL ="<<null;
//        return true;
//    }
//    else{
//        qDebug()<<query.lastError().text();
//        return false;
//    }
//}

//bool setFieldDefault(const QString &tableName, const QString &fieldName,const QString &value){
//    QSqlQuery query(Global::db);
//    QString sql = QString("ALTER TABLE %1 ALTER %2 SET DEFAULT %3;").arg(tableName,fieldName,value);
//    if(query.exec(sql)){
//        qDebug()<<value<<"was set into"<<fieldName<<"in"<<tableName;
//        return true;
//    }
//    else{
//        qDebug()<<query.lastError().text();
//        return false;
//    }
//}

//bool delField(const QString &tableName, const QString &fieldName){
//    QSqlQuery query(Global::db);
//    QString sql = QString("ALTER TABLE %1 DROP %2;").arg(tableName,fieldName);
//    if(query.exec(sql)){
//        qDebug()<<fieldName<<"in"<<tableName<<"was deleted.";
//        return true;
//    }
//    else{
//        qDebug()<<query.lastError().text();
//        return false;
//    }
//}

//bool delFieldDefault(const QString &tableName, const QString &fieldName){
//    QSqlQuery query(Global::db);
//    QString sql = QString("ALTER TABLE %1 ALTER %2 DROP DEFAULT;").arg(tableName,fieldName);
//    if(query.exec(sql)){
//        qDebug()<<fieldName<<"Default has been deleted"<<"in"<<tableName;
//        return true;
//    }
//    else{
//        qDebug()<<query.lastError().text();
//        return false;
//    }
//}

//bool delTable(const QString &tableName){
//    QSqlQuery query(Global::db);
//    QString sql = QString("DROP TABLE %1;").arg(tableName);
//    if(query.exec(sql)){
//        qDebug()<<tableName<<"was deleted.";
//        return true;
//    }
//    else{
//        qDebug()<<query.lastError().text();
//        return false;
//    }
//}

//bool delAllRecord(const QString &tableName){
//    QSqlQuery query(Global::db);
//    QString sql = QString("DELETE FROM %1;").arg(tableName);
//    if(query.exec(sql)){
//        qDebug()<<tableName<<"record was deleted.";
//        return true;
//    }
//    else{
//        qDebug()<<query.lastError().text();
//        return false;
//    }
//}

//bool delRecordByFieldValue(const QString &tableName,const QString &fieldName,const QString &value){
//    QSqlQuery query(Global::db);
//    QString sql = QString("DELETE FROM %1 WHERE %2 = '%3';").arg(tableName,fieldName,value);
//    if(query.exec(sql)){
//        qDebug()<<value<<"record deleted.";
//        return true;
//    }
//    else{
//        qDebug()<<query.lastError().text();
//        return false;
//    }
//}

//QStringList findAllRecord(const QString &tableName){
//    QSqlQuery query(Global::db);
//    QString sql = QString("SELECT * FROM %1;").arg(tableName);
//    QStringList allRecord;
//    if(!query.exec(sql)){
//        allRecord<<query.lastError().text();
//        return allRecord;
//    }
//    QSqlRecord rec = query.record();
//    while(query.next()){
//        for(int i = 0;i<rec.count();i++){
//            allRecord<<query.value(i).toString();
//        }
//        allRecord<<"/";
//    }
//    allRecord.removeLast();
//    return allRecord;
//}

//QStringList findRecordByFieldValue(const QString &tableName,const QString &fieldName,const QString &value){
//    QSqlQuery query(Global::db);
//    QString sql = QString("SELECT * FROM %1 WHERE %2 = '%3';").arg(tableName,fieldName,value);
//    QStringList record;
//    if(!query.exec(sql)){
//        record<<query.lastError().text();
//        return record;
//    }
//    QSqlRecord rec = query.record();
//    while(query.next()){
//        for(int i = 0;i<rec.count();i++){
//            record<<query.value(i).toString();
//        }
//        record<<"/";
//    }
//    record.removeLast();
//    return record;
//}

//QStringList findAccountInfoById(const QString &uid){
//    QSqlQuery query(Global::db);
//    QString sql = QString("SELECT * FROM account WHERE uid = '%1';").arg(uid);
//    QStringList accountInfo;
//    query.exec(sql);
//    if(query.first()){
//        accountInfo<<query.value("uid").toString()<<query.value("pwd").toString()<<query.value("email").toString();
//    }
//    else{
//        accountInfo<<query.lastError().text();
//    }
//    return accountInfo;
//}

//QStringList findAccountInfoByEmail(const QString &email){
//    QSqlQuery query(Global::db);
//    QString sql = QString("SELECT * FROM account WHERE email = '%1';").arg(email);
//    QStringList accountInfo;
//    query.exec(sql);
//    if(query.first()){
//        accountInfo<<query.value("uid").toString()<<query.value("pwd").toString()<<query.value("email").toString();
//    }
//    else{
//        accountInfo<<query.lastError().text();
//    }
//    return accountInfo;
//}

//bool renameTable(const QString &oldName,const QString &newName){
//    QSqlQuery query(Global::db);
//    QString sql = QString("ALTER TABLE %1 RENAME TO %2;").arg(oldName,newName);
//    if(query.exec(sql)){
//        qDebug()<<oldName<<"has been renamed to"<<newName;
//        return true;
//    }
//    else{
//        qDebug()<<query.lastError().text();
//        return false;
//    }
//}

//bool changeField(const QString &tableName, const QString &oldField, const QString &newField, const QString &fieldType){
//    QSqlQuery query(Global::db);
//    QString sql = QString("ALTER TABLE %1 CHANGE %2 %3 %4;").arg(tableName,oldField,newField,fieldType);
//    if(query.exec(sql)){
//        qDebug()<<oldField<<"has been changed to"<<newField<<"of which fieldType ="<<fieldType<<"in"<<tableName;
//        return true;
//    }
//    else{
//        qDebug()<<query.lastError().text();
//        return false;
//    }
//}

//bool changeFieldType(const QString &tableName, const QString &fieldName, const QString &fieldType, const bool &null){
//    QSqlQuery query(Global::db);
//    QString sql = QString("ALTER TABLE %1 MODIFY %2 %3").arg(tableName,fieldName,fieldType);
//    if(null){
//        sql += ";";
//    }
//    else{
//        sql += " NOT NULL;";
//    }
//    if(query.exec(sql)){
//        qDebug()<<fieldName<<"type has been changed to"<<fieldType;
//        return true;
//    }
//    else{
//        qDebug()<<query.lastError().text();
//        return false;
//    }
//}

//bool changeUid(const QString &oldUid, const QString &newUid){
//    QSqlQuery query(Global::db);
//    QString sql = QString("UPDATE account SET uid = '%1' WHERE uid = '%2'").arg(newUid,oldUid);
//    if(query.exec(sql)){
//        qDebug()<<query.numRowsAffected()<<"Uid(s) changed.";
//        return true;
//    }
//    else{
//        qDebug()<<query.lastError().text();
//        return false;
//    }
//}

//bool changePwdByUid(const QString &Uid, const QString &newPwd){
//    QSqlQuery query(Global::db);
//    QString sql = QString("UPDATE account SET pwd = '%1' WHERE uid = '%2'").arg(newPwd,Uid);
//    if(query.exec(sql)){
//        qDebug()<<query.numRowsAffected()<<"Pwd(s) changed.";
//        return true;
//    }
//    else{
//        qDebug()<<query.lastError().text();
//        return false;
//    }
//}

//bool changePwdByEmail(const QString &email, const QString &newPwd){
//    QSqlQuery query(Global::db);
//    QString sql = QString("UPDATE account SET pwd = '%1' WHERE email = '%2'").arg(newPwd,email);
//    if(query.exec(sql)){
//        qDebug()<<query.numRowsAffected()<<"Pwd(s) changed.";
//        return true;
//    }
//    else{
//        qDebug()<<query.lastError().text();
//        return false;
//    }
//}
