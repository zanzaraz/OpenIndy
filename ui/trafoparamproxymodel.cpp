#include "trafoparamproxymodel.h"

TrafoParamProxyModel::TrafoParamProxyModel(QList<FeatureWrapper*> &features,QObject *parent) :
    QSortFilterProxyModel(parent),features(features)
{
}

bool TrafoParamProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const{
    //return true;
    if(this->features.at(source_row)->getTrafoParam() != NULL){
        return true;
    }else{
        return false;
    }
}

bool TrafoParamProxyModel::filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const{
    if(source_column == 0 || source_column == 1 || source_column == 6 || source_column == 8
            || source_column == 18 || source_column == 19 || source_column == 20 || source_column == 21 || source_column == 22
            || source_column == 23 || source_column == 24 || source_column == 25 || source_column == 26 || source_column == 27
            || source_column == 28){
        return true;
    }else{
        return false;
    }

}
