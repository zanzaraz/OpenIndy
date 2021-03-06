#include "systemdbmanager.h"

QSqlDatabase SystemDbManager::db;
bool SystemDbManager::isInit = false;


/*!
 * \brief SystemDbManager::getCreateFunctionModel
 * Set up model with all available function plugins for the specified feature type
 * \param sqlModel
 * \param ft
 * \return
 */
bool SystemDbManager::getCreateFunctionModel(QSqlQueryModel *sqlModel, Configuration::FeatureTypes ft){
    sqlModel->clear();
    if(!SystemDbManager::isInit){ SystemDbManager::init(); }
    bool check = false;
    if(SystemDbManager::connect()){

        QString feature = OiMetaData::findFeature(ft);

        QString query;
        if(ft == Configuration::eTrafoParamFeature){ //trafo param is defined by system transformation
            query = QString("SELECT fp.name, fp.description, fp.iid, p.file_path FROM elementPlugin AS ep "
                                    "INNER JOIN functionPlugin AS fp ON fp.id = ep.functionPlugin_id "
                                    "INNER JOIN plugin AS p ON p.id = fp.plugin_id "
                                    "WHERE ep.element_id = %1 "
                                    "AND (fp.iid = \'" + OiMetaData::iid_SystemTransformation + "\');")
                    .arg(SystemDbManager::getElementId(feature));
        }else{ //all other features are defined by fit or construct function
            query = QString("SELECT fp.name, fp.description, fp.iid, p.file_path FROM elementPlugin AS ep "
                                    "INNER JOIN functionPlugin AS fp ON fp.id = ep.functionPlugin_id "
                                    "INNER JOIN plugin AS p ON p.id = fp.plugin_id "
                                    "WHERE ep.element_id = %1 "
                                    "AND (fp.iid = \'" + OiMetaData::iid_FitFunction + "\' OR fp.iid = \'" + OiMetaData::iid_ConstructFunction + "\');")
                    .arg(SystemDbManager::getElementId(feature));
        }


        sqlModel->setQuery(query, SystemDbManager::db);

        if(sqlModel->lastError().isValid()){
            Console::addLine( QString("Database error: %1").arg(sqlModel->lastError().text()) );
        }else{ check = true; }

        SystemDbManager::disconnect();
    }
    return check;
}

/*!
 * \brief SystemDbManager::getChangeFunctionModel
 * Set up model with all available function plugins for the specified feature type
 * \param sqlModel
 * \param ft
 * \return
 */
bool SystemDbManager::getChangeFunctionModel(QSqlQueryModel *sqlModel, Configuration::FeatureTypes ft){
    sqlModel->clear();
    if(!SystemDbManager::isInit){ SystemDbManager::init(); }
    bool check = false;
    if(SystemDbManager::connect()){

        QString feature = OiMetaData::findFeature(ft);

        QString query = QString("SELECT fp.name, fp.description, fp.iid, p.file_path FROM elementPlugin AS ep "
                                "INNER JOIN functionPlugin AS fp ON fp.id = ep.functionPlugin_id "
                                "INNER JOIN plugin AS p ON p.id = fp.plugin_id "
                                "WHERE ep.element_id = %1 "
                                "AND NOT (fp.iid = \'" + OiMetaData::iid_FitFunction + "\' "
                                "OR fp.iid = \'" + OiMetaData::iid_ConstructFunction + "\' "
                                "OR fp.iid = \'" + OiMetaData::iid_SystemTransformation + "\');")
                .arg(SystemDbManager::getElementId(feature));

        sqlModel->setQuery(query, SystemDbManager::db);

        if(sqlModel->lastError().isValid()){
            Console::addLine( QString("Database error: %1").arg(sqlModel->lastError().text()) );
        }else{ check = true; }

        SystemDbManager::disconnect();
    }
    return check;
}

/*!
 * \brief SystemDbManager::getNeededFeatures
 * Get all needed elements for the function plugin with the specified id
 * \param sqlModel
 * \param id
 * \return
 */
bool SystemDbManager::getNeededElements(QSqlQueryModel *sqlModel, int id){
    sqlModel->clear();
    if(!SystemDbManager::isInit){ SystemDbManager::init(); }
    bool check = false;
    if(SystemDbManager::connect()){
        QString query = QString("SELECT e.id, e.element_type, pe.element_infinite FROM pluginElement AS pe "
                                "INNER JOIN element AS e ON pe.element_id = e.id "
                                "WHERE pe.functionPlugin_id = %1").arg(id);

        sqlModel->setQuery(query, SystemDbManager::db);

        if(sqlModel->lastError().isValid()){
            Console::addLine( QString("Database error: %1").arg(sqlModel->lastError().text()) );
        }else{ check = true; }

        SystemDbManager::disconnect();
    }
    return check;
}

/*!
 * \brief SystemDbManager::getLaserTrackerModel
 * Fill QSqlQueryModel with all available Lasertracker Plugins
 * \param sqlModel
 * \return
 */
bool SystemDbManager::getLaserTrackerModel(QSqlQueryModel *sqlModel){
    sqlModel->clear();
    if(!SystemDbManager::isInit){ SystemDbManager::init(); }
    bool check = false;
    if(SystemDbManager::connect()){
        QString query = QString("SELECT sp.name, sp.description, p.name AS plugin, p.file_path FROM sensorPlugin AS sp INNER JOIN plugin AS p "
                                "ON sp.plugin_id = p.id WHERE sp.iid = '%1';")
            .arg(OiMetaData::iid_LaserTracker);

        sqlModel->setQuery(query, SystemDbManager::db);

        if(sqlModel->lastError().isValid()){
            Console::addLine( QString("Database error: %1").arg(sqlModel->lastError().text()) );
        }else{ check = true; }

        SystemDbManager::disconnect();
    }
    return check;
}

/*!
 * \brief SystemDbManager::getTotalStationModel
 * Fill QSqlQueryModel with all available Totalstation Plugins
 * \param sqlModel
 * \return
 */
bool SystemDbManager::getTotalStationModel(QSqlQueryModel *sqlModel){
    sqlModel->clear();
    if(!SystemDbManager::isInit){ SystemDbManager::init(); }
    bool check = false;
    if(SystemDbManager::connect()){
        QString query = QString("SELECT sp.name, sp.description, p.name AS plugin, p.file_path FROM sensorPlugin AS sp INNER JOIN plugin AS p "
                                "ON sp.plugin_id = p.id WHERE sp.iid = '%1';")
            .arg(OiMetaData::iid_TotalStation);

        sqlModel->setQuery(query, SystemDbManager::db);

        if(sqlModel->lastError().isValid()){
            Console::addLine( QString("Database error: %1").arg(sqlModel->lastError().text()) );
        }else{ check = true; }

        SystemDbManager::disconnect();
    }
    return check;
}

bool SystemDbManager::getUndefinedSensorModel(QSqlQueryModel *sqlModel){
    sqlModel->clear();
    if(!SystemDbManager::isInit){ SystemDbManager::init(); }
    bool check = false;
    if(SystemDbManager::connect()){
        QString query = QString("SELECT sp.name, sp.description, p.name AS plugin, p.file_path FROM sensorPlugin AS sp INNER JOIN plugin AS p "
                                "ON sp.plugin_id = p.id WHERE sp.iid = '%1';")
            .arg(OiMetaData::iid_Sensor);

        sqlModel->setQuery(query, SystemDbManager::db);

        if(sqlModel->lastError().isValid()){
            Console::addLine( QString("Database error: %1").arg(sqlModel->lastError().text()) );
        }else{ check = true; }

        SystemDbManager::disconnect();
    }
    return check;
}

/*!
 * \brief SystemDbManager::getPluginFilePath
 * Get filepath to the plugin with the name "plugin" which contains the function with the name "name"
 * \param name
 * \param plugin
 * \return
 */
QString SystemDbManager::getPluginFilePath(QString name, QString plugin){
    QString path = QString("");
    if(!SystemDbManager::isInit){ SystemDbManager::init(); }
    if(SystemDbManager::connect()){
        QString query = QString("%1 %2 %3")
                .arg("SELECT file_path FROM plugin AS p INNER JOIN functionPlugin AS fp ON p.id = fp.plugin_id")
                .arg(QString("WHERE p.name = '%1'").arg(plugin))
                .arg(QString("AND fp.name = '%1';").arg(name));
        QSqlQuery command(SystemDbManager::db);
        command.exec(query);
        if(command.next()){ //if the desired plugin element is a function
            QVariant val = command.value(0);
            if(val.isValid()){
                path = val.toString();
            }
        }else{
            query = QString("%1 %2 %3")
                    .arg("SELECT file_path FROM plugin AS p INNER JOIN sensorPlugin AS sp ON p.id = sp.plugin_id")
                    .arg(QString("WHERE p.name = '%1'").arg(plugin))
                    .arg(QString("AND sp.name = '%1';").arg(name));
            command.finish();
            command.exec(query);
            if(command.next()){ //if the desired plugin element is a sensor
                QVariant val = command.value(0);
                if(val.isValid()){
                    path = val.toString();
                }
            }else{
                query = QString("%1 %2 %3")
                        .arg("SELECT file_path FROM plugin AS p INNER JOIN networkAdjustmentPlugin AS nap ON p.id = sp.plugin_id")
                        .arg(QString("WHERE p.name = '%1'").arg(plugin))
                        .arg(QString("AND nap.name = '%1';").arg(name));
                command.finish();
                command.exec(query);
                if(command.next()){ //if the desired plugin element is a network adjustment
                    QVariant val = command.value(0);
                    if(val.isValid()){
                        path = val.toString();
                    }
                }
            }
        }
    }
    return path;
}

/*!
 * \brief SystemDbManager::savePlugin
 * Save the specified plugin in the system database of OpenIndy
 * \param metaInfo
 * \param f
 * \return
 */
int SystemDbManager::savePlugin(PluginMetaData *metaInfo, QList<Function*> functions, QList<Sensor*> sensors, QList<NetworkAdjustment*> networkAdjustments){
    int pluginId = -1;
    if(!SystemDbManager::isInit){ SystemDbManager::init(); }
    if(SystemDbManager::connect()){

        bool transaction = SystemDbManager::db.transaction();
        if(transaction){

            //save Plugin
            pluginId = SystemDbManager::savePluginHelper(metaInfo);

            //if the plugin was saved
            if(pluginId > -1){

                foreach(Function* f, functions){
                    SystemDbManager::saveFunctionPlugin(pluginId, f);
                }
                foreach(Sensor* s, sensors){
                    SystemDbManager::saveSensorPlugin(pluginId, s);
                }
                foreach(NetworkAdjustment* n, networkAdjustments){
                    SystemDbManager::saveNetworkAdjustmentPlugin(pluginId, n);
                }

            }

            if(!SystemDbManager::db.commit()){
                SystemDbManager::db.rollback();
            }

        }else{
            Console::addLine( QString("Database error: %1").arg(SystemDbManager::db.lastError().text()) );
        }

        SystemDbManager::disconnect();
    }
    return pluginId;
}

/*!
 * \brief SystemDbManager::deletePlugin
 * Delete the specified plugin and all dependencies
 * \param id
 * \return
 */
bool SystemDbManager::deletePlugin(int id){
    bool check = false;
    if(!SystemDbManager::isInit){ SystemDbManager::init(); }
    if(SystemDbManager::connect()){

        //start transaction to delete in all tables
        bool transaction = SystemDbManager::db.transaction();
        if(transaction){

            QString query = QString("DELETE FROM elementPlugin WHERE plugin_id = %1").arg(id);
            QSqlQuery command(SystemDbManager::db);
            command.exec(query);

            query = QString("DELETE FROM pluginElement WHERE plugin_id =%1").arg(id);
            command.exec(query);

            query = QString("DELETE FROM plugin WHERE id = %1").arg(id);
            command.exec(query);

            if( !SystemDbManager::db.commit() ){
                Console::addLine( QString("Database error: %1").arg(command.lastError().text()) );
            }else{ check = true; }

        }else{
            Console::addLine( QString("Database error: %1").arg(SystemDbManager::db.lastError().text()) );
        }

        SystemDbManager::disconnect();
    }
    return check;
}

/*!
 * \brief SystemDbManager::init
 * Initialize OpenIndy system database
 */
void SystemDbManager::init(){

    SystemDbManager::db = QSqlDatabase::addDatabase("QSQLITE", "oisystemdb");

#ifdef Q_OS_MAC
    QString dbPath(qApp->applicationDirPath());
#endif

#ifdef Q_OS_WIN
    QString dbPath(qApp->applicationDirPath());
#endif

#ifdef Q_OS_LINUX
    QString dbPath(qApp->applicationDirPath());
#endif

    dbPath.append("/oisystemdb.sqlite");

    SystemDbManager::db.setDatabaseName(dbPath);
    SystemDbManager::isInit = true;
}

/*!
 * \brief SystemDbManager::connect
 * Connect to OpenIndy system database
 * \return
 */
bool SystemDbManager::connect(){
    QFileInfo checkFile(SystemDbManager::db.databaseName());

    if(checkFile.isFile()){
        SystemDbManager::db.open();
    }
    return SystemDbManager::db.isOpen();
}

/*!
 * \brief SystemDbManager::disconnect
 * Disconnect from OpenIndy system database
 */
void SystemDbManager::disconnect(){
    if(SystemDbManager::db.isOpen()){
        SystemDbManager::db.close();
    }
}

/*!
 * \brief SystemDbManager::getElementId
 * Get the id of the specified element.
 * Returns -1 if the element does not exist.
 * \param feature
 * \return
 */
int SystemDbManager::getElementId(QString element){
    QString query = QString("SELECT id FROM element WHERE element_type = '%1'").arg(element);
    QSqlQuery command(SystemDbManager::db);
    command.exec(query);
    if(command.next()){
        QVariant val = command.value(0);
        if(val.isValid()){
            return val.toInt();
        }
    }
    return -1;
}

/*!
 * \brief SystemDbManager::getElementIds
 * Get the id's of the specified elements
 * \param elements
 * \return
 */
QList<int> SystemDbManager::getElementIds(QList<QString> elements){
    QList<int> result;
    if(elements.length() > 0){
        QString query = QString("SELECT id FROM element WHERE element_type = '%1'").arg(elements.at(0));
        for(int i = 1; i < elements.length(); i++){
            query.append( QString(" OR element_type = '%1'").arg(elements.at(i)) );
        }
        QSqlQuery command(SystemDbManager::db);
        command.exec(query);
        while(command.next()){
            QVariant val = command.value(0);
            if(val.isValid()){
                result.append(val.toInt());
            }
        }
    }
    return result;
}

/*!
 * \brief SystemDbManager::getLastId
 * Get Id of the last inserted row of the specified table
 * \param table
 * \return
 */
int SystemDbManager::getLastId(QString table){
    int id = -1;
    if(table.compare("")){
        QString query = QString("SELECT max(id) FROM %1").arg(table);
        QSqlQuery command(SystemDbManager::db);
        command.exec(query);
        if(command.next()){
            QVariant val = command.value(0);
            if(val.isValid()){
                id = val.toInt();
            }
        }
    }
    return id;
}

/*!
 * \brief SystemDbManager::savePluginHelper
 * Save plugin to database
 * \return
 */
int SystemDbManager::savePluginHelper(PluginMetaData *metaInfo){
    int pluginId = -1;

    QString query = QString("INSERT INTO plugin (iid, name, description, version, author, compiler, operating_sys, "
                            "has_dependencies, file_path, is_active) VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', %8, '%9', %10);")
        .arg(metaInfo->iid).arg(metaInfo->name).arg(metaInfo->description).arg(metaInfo->pluginVersion)
        .arg(metaInfo->author).arg(metaInfo->compiler).arg(metaInfo->operatingSystem).arg(QString(metaInfo->dependencies?"1":"0"))
        .arg(metaInfo->path).arg("1");

    QSqlQuery command(SystemDbManager::db);
    bool check = command.exec(query);

    if(check){
        pluginId = SystemDbManager::getLastId("plugin");
    }

    if(command.lastError().isValid()){
        Console::addLine(query);
        Console::addLine( QString("Database error: %1").arg(command.lastError().text()) );
        pluginId = -1;
    }

    return pluginId;
}

/*!
 * \brief SystemDbManager::saveFunctionPlugin
 * \param pluginId
 * \param f
 */
void SystemDbManager::saveFunctionPlugin(int pluginId, Function* f){
    QList<QString> elements;

    //get id's of features for which this plugin is applicable
    QList<Configuration::FeatureTypes> lf = f->applicableFor();
    for(int i=0; i<lf.size(); i++){
        elements.append( OiMetaData::findFeature(lf.at(i)) );
    }
    QList<int> applicableFor = SystemDbManager::getElementIds(elements);

    elements.clear();

    //get id's of elements which this plugin needs to be able to execute
    QList<InputParams> le = f->getNeededElements();
    for(int i=0; i<le.size(); i++){
        elements.append( OiMetaData::findElement(le.at(i).typeOfElement) );
    }
    QList<int> neededElements = SystemDbManager::getElementIds(elements);

    if(applicableFor.length() > 0 && neededElements.length() > 0){
        //insert function plugin
        QString query = QString("INSERT INTO functionPlugin (plugin_id, iid, name, description) VALUES (%1, '%2', '%3', '%4')")
                .arg(pluginId).arg(f->getMetaData()->iid).arg(f->getMetaData()->name).arg(f->getMetaData()->description);
        QSqlQuery command(SystemDbManager::db);
        command.exec(query);

        //get id of function plugin
        pluginId = SystemDbManager::getLastId("functionPlugin");

        if(pluginId > -1){
            //insert needed elements
            query = QString("INSERT INTO pluginElement (functionPlugin_id, element_id, element_infinite) VALUES (%1, %2, %3)")
                    .arg(pluginId).arg(neededElements.at(0)).arg(le.at(0).infinite?"1":"0");
            for(int i = 1; i < neededElements.length(); i++){
                query.append(QString(", (%1, %2, %3)").arg(pluginId).arg(neededElements.at(i)).arg(le.at(i).infinite?"1":"0"));
            }
            command.exec(query);

            //insert applicable for
            query = QString("INSERT INTO elementPlugin (functionPlugin_id, element_id) VALUES (%1, %2)")
                    .arg(pluginId).arg(applicableFor.at(0));
            for(int i = 1; i < applicableFor.length(); i++){
                query.append( QString(", (%1, %2)").arg(pluginId).arg(applicableFor.at(i)) );
            }
            command.exec(query);
        }
    }
}

/*!
 * \brief SystemDbManager::saveSensorPlugin
 * \param pluginId
 * \param s
 */
void SystemDbManager::saveSensorPlugin(int pluginId, Sensor* s){
    //insert sensor plugin
    QString query = QString("INSERT INTO sensorPlugin (plugin_id, iid, name, description) VALUES (%1, '%2', '%3', '%4')")
            .arg(pluginId).arg(s->getMetaData()->iid).arg(s->getMetaData()->name).arg(s->getMetaData()->description);
    QSqlQuery command(SystemDbManager::db);
    command.exec(query);
}

/*!
 * \brief SystemDbManager::saveNetworkAdjustmentPlugin
 * \param pluginId
 * \param n
 */
void SystemDbManager::saveNetworkAdjustmentPlugin(int pluginId, NetworkAdjustment* n){
    //insert network adjustment plugin
    /*QString query = QString("INSERT INTO sensorPlugin (plugin_id, iid, name, description) VALUES (%1, '%2', '%3', '%4')")
            .arg(pluginId).arg(s->getMetaData()->iid).arg(s->getMetaData()->name).arg(s->getMetaData()->description);
    QSqlQuery command(SystemDbManager::db);
    command.exec(query);*/
}
