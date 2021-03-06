#ifndef FEATURETREEVIEWMODEL_H
#define FEATURETREEVIEWMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QPixmap>

#include "featuretreeitem.h"

class FeatureTreeViewModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit FeatureTreeViewModel(QList<FeatureWrapper*> &features, QObject *parent = 0);

    QModelIndex	index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
    QModelIndex	parent(const QModelIndex & index) const;
    int	rowCount(const QModelIndex & parent = QModelIndex()) const;
    int	columnCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    void refreshModel();
    FeatureTreeItem* getRootItem() const;

private:
    QList<FeatureWrapper*> &features;
    FeatureTreeItem *rootItem;

    void appendGeometries(FeatureTreeItem *root, QList<FeatureWrapper*> geometries, QString geomType);
    void appendCoordinateSystems(FeatureTreeItem *root, QList<FeatureWrapper*> coordinateSystems);
    void appendStations(FeatureTreeItem *root, QList<FeatureWrapper*> stations);
    void appendTrafoParams(FeatureTreeItem *root, QList<FeatureWrapper*> trafoParams);

    void appendObservation(FeatureTreeItem *root, Observation *obs);
    void appendReading(FeatureTreeItem *root, Observation *obs);

};

#endif // FEATURETREEVIEWMODEL_H
