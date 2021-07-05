#ifndef API_SQL_H
#define API_SQL_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "class_task.h"
#include "global.h"
#include <QSqlRecord>

// 建
bool connect();
bool createTable(const QString &tableName,const QStringList &tableHeadList);

// 增
bool insert(const QString &tableName, const QString &field, const QString &value);
bool insert(const QString &tableName, const QString &field, const QDate &value);
bool insert(const QString &tableName, const QString &field, const QTime &value);
bool insertOne(const QString &tableName, const QStringList &fieldList, const QStringList &valueList);
bool insertMany(const QString &tableName,const QStringList &fieldList,const QStringList &valueList);
bool addField(const QString &tableName, const QString &fieldName, const QString &fieldType, const bool &binary = true, const bool &null = true);


// 删
bool delField(const QString &tableName, const QString &fieldName);
bool delFieldDefault(const QString &tableName, const QString &fieldName);
bool delTable(const QString &tableName);
bool delAllRecord(const QString &tableName);
bool delRecordByFieldValue(const QString &tableName,const QString &fieldName,const QString &value);

// 查
QStringList findAllRecord(const QString &tableName);
QStringList findRecordByFieldValue(const QString &tableName,const QString &fieldName,const QString &value);

QStringList findAccountInfoById(const QString &uid);
QStringList findAccountInfoByEmail(const QString &email);

// 改
bool renameTable(const QString &oldName, const QString &newName);
bool changeField(const QString &tableName, const QString &oldField, const QString &newField, const QString &fieldType);
bool changeFieldType(const QString &tableName, const QString &fieldName, const QString &fieldType, const bool &null = true);
bool setFieldDefault(const QString &tableName, const QString &fieldName, const QString &value);

bool changeUid(const QString &oldUid, const QString &newUid);
bool changePwdByUid(const QString &Uid, const QString &newPwd);
bool changePwdByEmail(const QString &email, const QString &newPwd);










#endif // API_SQL_H
