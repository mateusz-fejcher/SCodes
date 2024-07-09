#include "SPermissionsController.h"
#include <QPermissions>
#include <QGuiApplication>

SPermissionsController::SPermissionsController(QObject *parent)
    : QObject{parent}
{
    m_timer = new QTimer(this);

    QObject::connect(m_timer, &QTimer::timeout, this, &SPermissionsController::checkPermissions);

    m_timer->setInterval(1000);
    m_timer->start();
}

void SPermissionsController::checkPermissions()
{
    QCameraPermission cameraPermission;

    switch (QGuiApplication::instance()->checkPermission(cameraPermission)) {
    case Qt::PermissionStatus::Undetermined:
        qDebug() << "Camera permission is Undetermined!";
        qApp->requestPermission(QCameraPermission{}, [](const QPermission &permission) {
        });
        break;
    case Qt::PermissionStatus::Denied:
        qDebug() << "Camera permission is not granted!";
        break;
    case Qt::PermissionStatus::Granted:
        qDebug() << "Camera permission is granted!";

        m_timer->stop();
        emit cameraPermissionGranted();
        break;
    }
}
