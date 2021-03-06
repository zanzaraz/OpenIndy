#include "nominaldatadialog.h"
#include "ui_nominaldatadialog.h"

NominalDataDialog::NominalDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NominalDataDialog)
{
    ui->setupUi(this);
    this->selectedFeature = NULL;
}

NominalDataDialog::~NominalDataDialog()
{
    delete ui;
}

void NominalDataDialog::getActiveFeature(FeatureWrapper *aF){

    ui->label_nominalI->setEnabled(false);
    ui->label_nominalJ->setEnabled(false);
    ui->label_nominalJ->setEnabled(false);
    ui->label_nominalX->setEnabled(false);
    ui->label_nominalY->setEnabled(false);
    ui->label_nominalZ->setEnabled(false);
    ui->label_nominalR->setEnabled(false);
    ui->lineEdit_nominalI->setEnabled(false);
    ui->lineEdit_nominalJ->setEnabled(false);
    ui->lineEdit_nominalJ->setEnabled(false);
    ui->lineEdit_nominalX->setEnabled(false);
    ui->lineEdit_nominalY->setEnabled(false);
    ui->lineEdit_nominalZ->setEnabled(false);
    ui->lineEdit_nominalR->setEnabled(false);
    ui->label_nominalSAE->setEnabled(false);
    ui->label_nominalSDE->setEnabled(false);
    ui->lineEdit_nominalSAE->setEnabled(false);
    ui->lineEdit_nominalSDE->setEnabled(false);
    ui->label_nominalMeasurementSeries->setEnabled(false);
    ui->lineEdit_nominalMeasurementSeries->setEnabled(false);
    ui->lineEdit_nominalTemperature->setEnabled(false);
    ui->label_nominalTemperature->setEnabled(false);

    this->setLabelText();

    this->selectedFeature = aF;
    this->setWindowTitle(QString("nominal data of " + this->selectedFeature->getFeature()->name));

    switch (selectedFeature->getTypeOfFeature()) {
    case Configuration::ePointFeature:
        ui->label_nominalI->setEnabled(false);
        ui->label_nominalJ->setEnabled(false);
        ui->label_nominalK->setEnabled(false);
        ui->label_nominalX->setEnabled(true);
        ui->label_nominalY->setEnabled(true);
        ui->label_nominalZ->setEnabled(true);
        ui->label_nominalR->setEnabled(false);
        ui->lineEdit_nominalI->setEnabled(false);
        ui->lineEdit_nominalJ->setEnabled(false);
        ui->lineEdit_nominalK->setEnabled(false);
        ui->lineEdit_nominalX->setEnabled(true);
        ui->lineEdit_nominalY->setEnabled(true);
        ui->lineEdit_nominalZ->setEnabled(true);
        ui->lineEdit_nominalR->setEnabled(false);
        ui->label_nominalSAE->setEnabled(false);
        ui->label_nominalSDE->setEnabled(false);
        ui->lineEdit_nominalSAE->setEnabled(false);
        ui->lineEdit_nominalSDE->setEnabled(false);
        ui->label_nominalMeasurementSeries->setEnabled(false);
        ui->lineEdit_nominalMeasurementSeries->setEnabled(false);
        ui->lineEdit_nominalTemperature->setEnabled(false);
        ui->label_nominalTemperature->setEnabled(false);
        break;
    case Configuration::ePlaneFeature:
        ui->label_nominalI->setEnabled(true);
        ui->label_nominalJ->setEnabled(true);
        ui->label_nominalK->setEnabled(true);
        ui->label_nominalX->setEnabled(true);
        ui->label_nominalY->setEnabled(true);
        ui->label_nominalZ->setEnabled(true);
        ui->label_nominalR->setEnabled(false);
        ui->lineEdit_nominalI->setEnabled(true);
        ui->lineEdit_nominalJ->setEnabled(true);
        ui->lineEdit_nominalK->setEnabled(true);
        ui->lineEdit_nominalX->setEnabled(true);
        ui->lineEdit_nominalY->setEnabled(true);
        ui->lineEdit_nominalZ->setEnabled(true);
        ui->lineEdit_nominalR->setEnabled(false);
        ui->label_nominalSAE->setEnabled(false);
        ui->label_nominalSDE->setEnabled(false);
        ui->lineEdit_nominalSAE->setEnabled(false);
        ui->lineEdit_nominalSDE->setEnabled(false);
        ui->label_nominalMeasurementSeries->setEnabled(false);
        ui->lineEdit_nominalMeasurementSeries->setEnabled(false);
        ui->lineEdit_nominalTemperature->setEnabled(false);
        ui->label_nominalTemperature->setEnabled(false);
        break;
    case Configuration::eLineFeature:
        ui->label_nominalI->setEnabled(true);
        ui->label_nominalJ->setEnabled(true);
        ui->label_nominalK->setEnabled(true);
        ui->label_nominalX->setEnabled(true);
        ui->label_nominalY->setEnabled(true);
        ui->label_nominalZ->setEnabled(true);
        ui->label_nominalR->setEnabled(false);
        ui->lineEdit_nominalI->setEnabled(true);
        ui->lineEdit_nominalJ->setEnabled(true);
        ui->lineEdit_nominalK->setEnabled(true);
        ui->lineEdit_nominalX->setEnabled(true);
        ui->lineEdit_nominalY->setEnabled(true);
        ui->lineEdit_nominalZ->setEnabled(true);
        ui->lineEdit_nominalR->setEnabled(false);
        ui->label_nominalSAE->setEnabled(false);
        ui->label_nominalSDE->setEnabled(false);
        ui->lineEdit_nominalSAE->setEnabled(false);
        ui->lineEdit_nominalSDE->setEnabled(false);
        ui->label_nominalMeasurementSeries->setEnabled(false);
        ui->lineEdit_nominalMeasurementSeries->setEnabled(false);
        ui->lineEdit_nominalTemperature->setEnabled(false);
        ui->label_nominalTemperature->setEnabled(false);
        break;
    case Configuration::eSphereFeature:
        ui->label_nominalI->setEnabled(false);
        ui->label_nominalJ->setEnabled(false);
        ui->label_nominalK->setEnabled(false);
        ui->label_nominalX->setEnabled(true);
        ui->label_nominalY->setEnabled(true);
        ui->label_nominalZ->setEnabled(true);
        ui->label_nominalR->setEnabled(true);
        ui->lineEdit_nominalI->setEnabled(false);
        ui->lineEdit_nominalJ->setEnabled(false);
        ui->lineEdit_nominalK->setEnabled(false);
        ui->lineEdit_nominalX->setEnabled(true);
        ui->lineEdit_nominalY->setEnabled(true);
        ui->lineEdit_nominalZ->setEnabled(true);
        ui->lineEdit_nominalR->setEnabled(true);
        ui->label_nominalSAE->setEnabled(false);
        ui->label_nominalSDE->setEnabled(false);
        ui->lineEdit_nominalSAE->setEnabled(false);
        ui->lineEdit_nominalSDE->setEnabled(false);
        ui->label_nominalMeasurementSeries->setEnabled(false);
        ui->lineEdit_nominalMeasurementSeries->setEnabled(false);
        ui->lineEdit_nominalTemperature->setEnabled(false);
        ui->label_nominalTemperature->setEnabled(false);
        break;
    case Configuration::eScalarentityAngleFeature:
        ui->label_nominalI->setEnabled(false);
        ui->label_nominalJ->setEnabled(false);
        ui->label_nominalK->setEnabled(false);
        ui->label_nominalX->setEnabled(false);
        ui->label_nominalY->setEnabled(false);
        ui->label_nominalZ->setEnabled(false);
        ui->label_nominalR->setEnabled(false);
        ui->lineEdit_nominalI->setEnabled(false);
        ui->lineEdit_nominalJ->setEnabled(false);
        ui->lineEdit_nominalK->setEnabled(false);
        ui->lineEdit_nominalX->setEnabled(false);
        ui->lineEdit_nominalY->setEnabled(false);
        ui->lineEdit_nominalZ->setEnabled(false);
        ui->lineEdit_nominalR->setEnabled(false);
        ui->label_nominalSAE->setEnabled(true);
        ui->label_nominalSDE->setEnabled(false);
        ui->lineEdit_nominalSAE->setEnabled(true);
        ui->lineEdit_nominalSDE->setEnabled(false);
        ui->label_nominalMeasurementSeries->setEnabled(false);
        ui->lineEdit_nominalMeasurementSeries->setEnabled(false);
        ui->lineEdit_nominalTemperature->setEnabled(false);
        ui->label_nominalTemperature->setEnabled(false);
        break;
    case Configuration::eScalarEntityDistanceFeature:
        ui->label_nominalI->setEnabled(false);
        ui->label_nominalJ->setEnabled(false);
        ui->label_nominalK->setEnabled(false);
        ui->label_nominalX->setEnabled(false);
        ui->label_nominalY->setEnabled(false);
        ui->label_nominalZ->setEnabled(false);
        ui->label_nominalR->setEnabled(false);
        ui->lineEdit_nominalI->setEnabled(false);
        ui->lineEdit_nominalJ->setEnabled(false);
        ui->lineEdit_nominalK->setEnabled(false);
        ui->lineEdit_nominalX->setEnabled(false);
        ui->lineEdit_nominalY->setEnabled(false);
        ui->lineEdit_nominalZ->setEnabled(false);
        ui->lineEdit_nominalR->setEnabled(false);
        ui->label_nominalSAE->setEnabled(false);
        ui->label_nominalSDE->setEnabled(true);
        ui->lineEdit_nominalSAE->setEnabled(false);
        ui->lineEdit_nominalSDE->setEnabled(true);
        ui->label_nominalMeasurementSeries->setEnabled(false);
        ui->lineEdit_nominalMeasurementSeries->setEnabled(false);
        ui->lineEdit_nominalTemperature->setEnabled(false);
        ui->label_nominalTemperature->setEnabled(false);
        break;
    case Configuration::eScalarEntityTemperatureFeature:
        ui->label_nominalI->setEnabled(false);
        ui->label_nominalJ->setEnabled(false);
        ui->label_nominalK->setEnabled(false);
        ui->label_nominalX->setEnabled(false);
        ui->label_nominalY->setEnabled(false);
        ui->label_nominalZ->setEnabled(false);
        ui->label_nominalR->setEnabled(false);
        ui->lineEdit_nominalI->setEnabled(false);
        ui->lineEdit_nominalJ->setEnabled(false);
        ui->lineEdit_nominalK->setEnabled(false);
        ui->lineEdit_nominalX->setEnabled(false);
        ui->lineEdit_nominalY->setEnabled(false);
        ui->lineEdit_nominalZ->setEnabled(false);
        ui->lineEdit_nominalR->setEnabled(false);
        ui->label_nominalSAE->setEnabled(false);
        ui->label_nominalSDE->setEnabled(false);
        ui->lineEdit_nominalSAE->setEnabled(false);
        ui->lineEdit_nominalSDE->setEnabled(false);
        ui->label_nominalMeasurementSeries->setEnabled(false);
        ui->lineEdit_nominalMeasurementSeries->setEnabled(false);
        ui->lineEdit_nominalTemperature->setEnabled(true);
        ui->label_nominalTemperature->setEnabled(true);
        break;
    case Configuration::eScalarEntityMeasurementSeriesFeature:
        ui->label_nominalI->setEnabled(false);
        ui->label_nominalJ->setEnabled(false);
        ui->label_nominalK->setEnabled(false);
        ui->label_nominalX->setEnabled(false);
        ui->label_nominalY->setEnabled(false);
        ui->label_nominalZ->setEnabled(false);
        ui->label_nominalR->setEnabled(false);
        ui->lineEdit_nominalI->setEnabled(false);
        ui->lineEdit_nominalJ->setEnabled(false);
        ui->lineEdit_nominalK->setEnabled(false);
        ui->lineEdit_nominalX->setEnabled(false);
        ui->lineEdit_nominalY->setEnabled(false);
        ui->lineEdit_nominalZ->setEnabled(false);
        ui->lineEdit_nominalR->setEnabled(false);
        ui->label_nominalSAE->setEnabled(false);
        ui->label_nominalSDE->setEnabled(false);
        ui->lineEdit_nominalSAE->setEnabled(false);
        ui->lineEdit_nominalSDE->setEnabled(false);
        ui->label_nominalMeasurementSeries->setEnabled(true);
        ui->lineEdit_nominalMeasurementSeries->setEnabled(true);
        ui->lineEdit_nominalTemperature->setEnabled(false);
        ui->label_nominalTemperature->setEnabled(false);
        break;
    default:
        ui->label_nominalI->setEnabled(false);
        ui->label_nominalJ->setEnabled(false);
        ui->label_nominalK->setEnabled(false);
        ui->label_nominalX->setEnabled(false);
        ui->label_nominalY->setEnabled(false);
        ui->label_nominalZ->setEnabled(false);
        ui->label_nominalR->setEnabled(false);
        ui->lineEdit_nominalI->setEnabled(false);
        ui->lineEdit_nominalJ->setEnabled(false);
        ui->lineEdit_nominalK->setEnabled(false);
        ui->lineEdit_nominalX->setEnabled(false);
        ui->lineEdit_nominalY->setEnabled(false);
        ui->lineEdit_nominalZ->setEnabled(false);
        ui->lineEdit_nominalR->setEnabled(false);
        ui->label_nominalSAE->setEnabled(false);
        ui->label_nominalSDE->setEnabled(false);
        ui->lineEdit_nominalSAE->setEnabled(false);
        ui->lineEdit_nominalSDE->setEnabled(false);
        ui->label_nominalMeasurementSeries->setEnabled(false);
        ui->lineEdit_nominalMeasurementSeries->setEnabled(false);
        ui->lineEdit_nominalTemperature->setEnabled(false);
        ui->label_nominalTemperature->setEnabled(false);
        break;
    }

    fillGUI();
}

void NominalDataDialog::on_toolButton_ok_clicked()
{
    double nomX = ui->lineEdit_nominalX->text().toDouble()/UnitConverter::getDistanceMultiplier();
    double nomY = ui->lineEdit_nominalY->text().toDouble()/UnitConverter::getDistanceMultiplier();
    double nomZ = ui->lineEdit_nominalZ->text().toDouble()/UnitConverter::getDistanceMultiplier();
    double nomI = ui->lineEdit_nominalI->text().toDouble();
    double nomJ = ui->lineEdit_nominalJ->text().toDouble();
    double nomK = ui->lineEdit_nominalK->text().toDouble();
    double nomR = ui->lineEdit_nominalR->text().toDouble()/UnitConverter::getDistanceMultiplier();
    double nomSDE = ui->lineEdit_nominalSDE->text().toDouble()/UnitConverter::getDistanceMultiplier();
    double nomSAE = ui->lineEdit_nominalSAE->text().toDouble()/UnitConverter::getAngleMultiplier();
    double nomSTE = ui->lineEdit_nominalTemperature->text().toDouble()/UnitConverter::getTemperatureMultiplier();
    double nomSMSE = ui->lineEdit_nominalMeasurementSeries->text().toDouble();

    emit sendNominalValues(nomX, nomY, nomZ, nomI, nomJ, nomK, nomR, nomSDE, nomSAE, nomSTE, nomSMSE);

    this->close();
}

void NominalDataDialog::on_toolButton_cancel_clicked()
{
    this->close();
}

void NominalDataDialog::setLabelText()
{
    ui->label_nominalI->setText(QString("nominal I value"));
    ui->label_nominalJ->setText(QString("nominal J value"));
    ui->label_nominalK->setText(QString("nominal K value"));
    ui->label_nominalMeasurementSeries->setText(QString("nominal measurement series"));
    ui->label_nominalR->setText(QString("nominal radius value " + UnitConverter::getDistanceUnitString()));
    ui->label_nominalSAE->setText(QString("nominal scalar entity angle value " + UnitConverter::getAngleUnitString()));
    ui->label_nominalSDE->setText(QString("nominal scalar distance value " + UnitConverter::getDistanceUnitString()));
    ui->label_nominalTemperature->setText(QString("nominal scalar entity temperature value " + UnitConverter::getTemperatureUnitString()));
    ui->label_nominalX->setText(QString("nominal X value " + UnitConverter::getDistanceUnitString()));
    ui->label_nominalY->setText(QString("nominal Y value " + UnitConverter::getDistanceUnitString()));
    ui->label_nominalZ->setText(QString("nominal Z value " + UnitConverter::getDistanceUnitString()));
}

void NominalDataDialog::fillGUI(){

    switch (selectedFeature->getTypeOfFeature()) {
    case Configuration::ePointFeature:
        ui->lineEdit_nominalX->setText(QString::number(selectedFeature->getPoint()->xyz.getAt(0)*UnitConverter::getDistanceMultiplier(),'f',UnitConverter::distanceDigits));
        ui->lineEdit_nominalY->setText(QString::number(selectedFeature->getPoint()->xyz.getAt(1)*UnitConverter::getDistanceMultiplier(),'f',UnitConverter::distanceDigits));
        ui->lineEdit_nominalZ->setText(QString::number(selectedFeature->getPoint()->xyz.getAt(2)*UnitConverter::getDistanceMultiplier(),'f',UnitConverter::distanceDigits));
        ui->lineEdit_nominalI->setText("");
        ui->lineEdit_nominalJ->setText("");
        ui->lineEdit_nominalK->setText("");
        ui->lineEdit_nominalMeasurementSeries->setText("");
        ui->lineEdit_nominalR->setText("");
        ui->lineEdit_nominalSAE->setText("");
        ui->lineEdit_nominalSDE->setText("");
        ui->lineEdit_nominalTemperature->setText("");
        break;
    case Configuration::ePlaneFeature:
        ui->lineEdit_nominalX->setText(QString::number(selectedFeature->getPlane()->xyz.getAt(0),'f',6));
        ui->lineEdit_nominalY->setText(QString::number(selectedFeature->getPlane()->xyz.getAt(1),'f',6));
        ui->lineEdit_nominalZ->setText(QString::number(selectedFeature->getPlane()->xyz.getAt(2),'f',6));
        ui->lineEdit_nominalI->setText(QString::number(selectedFeature->getPlane()->ijk.getAt(0),'f',6));
        ui->lineEdit_nominalJ->setText(QString::number(selectedFeature->getPlane()->ijk.getAt(1),'f',6));
        ui->lineEdit_nominalK->setText(QString::number(selectedFeature->getPlane()->ijk.getAt(2),'f',6));
        ui->lineEdit_nominalMeasurementSeries->setText("");
        ui->lineEdit_nominalR->setText("");
        ui->lineEdit_nominalSAE->setText("");
        ui->lineEdit_nominalSDE->setText("");
        ui->lineEdit_nominalTemperature->setText("");
        break;
    case Configuration::eLineFeature:
        ui->lineEdit_nominalX->setText(QString::number(selectedFeature->getLine()->xyz.getAt(0),'f',6));
        ui->lineEdit_nominalY->setText(QString::number(selectedFeature->getLine()->xyz.getAt(1),'f',6));
        ui->lineEdit_nominalZ->setText(QString::number(selectedFeature->getLine()->xyz.getAt(2),'f',6));
        ui->lineEdit_nominalI->setText(QString::number(selectedFeature->getLine()->ijk.getAt(0),'f',6));
        ui->lineEdit_nominalJ->setText(QString::number(selectedFeature->getLine()->ijk.getAt(1),'f',6));
        ui->lineEdit_nominalK->setText(QString::number(selectedFeature->getLine()->ijk.getAt(2),'f',6));
        ui->lineEdit_nominalMeasurementSeries->setText("");
        ui->lineEdit_nominalR->setText("");
        ui->lineEdit_nominalSAE->setText("");
        ui->lineEdit_nominalSDE->setText("");
        ui->lineEdit_nominalTemperature->setText("");
        break;
    case Configuration::eSphereFeature:
        ui->lineEdit_nominalX->setText(QString::number(selectedFeature->getSphere()->xyz.getAt(0),'f',6));
        ui->lineEdit_nominalY->setText(QString::number(selectedFeature->getSphere()->xyz.getAt(1),'f',6));
        ui->lineEdit_nominalZ->setText(QString::number(selectedFeature->getSphere()->xyz.getAt(2),'f',6));
        ui->lineEdit_nominalR->setText(QString::number(selectedFeature->getSphere()->radius,'f',6));
        ui->lineEdit_nominalMeasurementSeries->setText("");
        ui->lineEdit_nominalSAE->setText("");
        ui->lineEdit_nominalSDE->setText("");
        ui->lineEdit_nominalTemperature->setText("");
        ui->lineEdit_nominalI->setText("");
        ui->lineEdit_nominalJ->setText("");
        ui->lineEdit_nominalK->setText("");
        break;
    case Configuration::eScalarentityAngleFeature:
        ui->lineEdit_nominalSAE->setText(QString::number(selectedFeature->getScalarEntityAngle()->getAngle()*180.0/3.141592653589793,'f',6));
        ui->lineEdit_nominalI->setText("");
        ui->lineEdit_nominalJ->setText("");
        ui->lineEdit_nominalK->setText("");
        ui->lineEdit_nominalMeasurementSeries->setText("");
        ui->lineEdit_nominalR->setText("");
        ui->lineEdit_nominalSDE->setText("");
        ui->lineEdit_nominalTemperature->setText("");
        ui->lineEdit_nominalX->setText("");
        ui->lineEdit_nominalY->setText("");
        ui->lineEdit_nominalZ->setText("");
        break;
    case Configuration::eScalarEntityDistanceFeature:
        ui->lineEdit_nominalSDE->setText(QString::number(selectedFeature->getScalarEntityDistance()->getDistance(),'f',6));
        ui->lineEdit_nominalI->setText("");
        ui->lineEdit_nominalJ->setText("");
        ui->lineEdit_nominalK->setText("");
        ui->lineEdit_nominalMeasurementSeries->setText("");
        ui->lineEdit_nominalR->setText("");
        ui->lineEdit_nominalSAE->setText("");
        ui->lineEdit_nominalTemperature->setText("");
        ui->lineEdit_nominalX->setText("");
        ui->lineEdit_nominalY->setText("");
        ui->lineEdit_nominalZ->setText("");
        break;
    case Configuration::eScalarEntityTemperatureFeature:
        ui->lineEdit_nominalI->setText("");
        ui->lineEdit_nominalJ->setText("");
        ui->lineEdit_nominalK->setText("");
        ui->lineEdit_nominalMeasurementSeries->setText("");
        ui->lineEdit_nominalR->setText("");
        ui->lineEdit_nominalSAE->setText("");
        ui->lineEdit_nominalTemperature->setText(QString::number(selectedFeature->getScalarEntityTemperature()->getTemperature()*UnitConverter::getTemperatureMultiplier(),'f',UnitConverter::temperatureDigits));
        ui->lineEdit_nominalX->setText("");
        ui->lineEdit_nominalY->setText("");
        ui->lineEdit_nominalZ->setText("");
        ui->lineEdit_nominalSDE->setText("");
        break;
    case Configuration::eScalarEntityMeasurementSeriesFeature:
        ui->lineEdit_nominalI->setText("");
        ui->lineEdit_nominalJ->setText("");
        ui->lineEdit_nominalK->setText("");
        ui->lineEdit_nominalMeasurementSeries->setText(QString::number(selectedFeature->getScalarEntityMeasurementSeries()->getSeriesValue(),'f',6));
        ui->lineEdit_nominalR->setText("");
        ui->lineEdit_nominalSAE->setText("");
        ui->lineEdit_nominalTemperature->setText("");
        ui->lineEdit_nominalX->setText("");
        ui->lineEdit_nominalY->setText("");
        ui->lineEdit_nominalZ->setText("");
        ui->lineEdit_nominalSDE->setText("");
        break;
    default:
        break;
    }
}
