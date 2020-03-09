#include "WindowPreferences.h"
#include "ui_formPreferences.h"
#include "Preferences.h"

#include <iostream>

WindowPreferences::WindowPreferences(QWidget *parent) : QWidget(parent), ui(new Ui::WindowPreferences) {
    ui->setupUi(this);
    setCurrentStateInUI();
}

void WindowPreferences::setCurrentStateInUI() {
/* Model settings */
    ui->countPoints->setValue(Preferences::AMOUNT_LOCUS);
    ui->pointsOneStart->setValue(Preferences::COUNT_POINTS);
    ui->xCoord->setValue(Preferences::START_POINT.x);
    ui->yCoord->setValue(Preferences::START_POINT.y);
    ui->zCoord->setValue(Preferences::START_POINT.z);

/* Camera settings */
    ui->sensSlider->setValue((Preferences::speedRotation - 0.0005) / (0.03 - 0.0005) * 100);
    ui->speedSlider->setValue((Preferences::speedMove - 0.05) / (0.3 - 0.05) * 100);

/* View settings */
    ui->tailSize->setValue(Preferences::AMOUNT_TAIL_POINTS);
    ui->tailsCheckBox->setDown(Preferences::TAILS_VIEW);
    if (Preferences::TAILS_VIEW)
        ui->tailsCheckBox->click();

}

void WindowPreferences::setStateFromUI() {
/* Model settings */
    Preferences::AMOUNT_LOCUS  = ui->countPoints->value();
    Preferences::COUNT_POINTS  = ui->pointsOneStart->value();
    Preferences::START_POINT.x = ui->xCoord->value();
    Preferences::START_POINT.y = ui->yCoord->value();
    Preferences::START_POINT.z = ui->zCoord->value();

/* Camera settings */
    Preferences::speedMove     = 0.05 + ui->speedSlider->value() / 100.0 * (0.3 - 0.05);
    Preferences::speedRotation = 0.0005 + ui->sensSlider->value() / 100.0 * (0.03 - 0.0005);

/* View settings */
    Preferences::AMOUNT_TAIL_POINTS = ui->tailSize->value();
    Preferences::TAILS_VIEW         = ui->tailsCheckBox->isDown();

    Preferences::NEW_PREFERENCES = true;
}

void WindowPreferences::slot_cancel_button() {
    setCurrentStateInUI();
    this->hide();
}

void WindowPreferences::slot_apply_button() {
    setStateFromUI();
    this->hide();
}

void WindowPreferences::slot_set_default_button() {
    Preferences::setDefaultValues();
    setCurrentStateInUI();
}

WindowPreferences::~WindowPreferences() {
    delete ui;
}