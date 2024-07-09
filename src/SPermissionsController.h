#ifndef SPERMISSIONSCONTROLLER_H
#define SPERMISSIONSCONTROLLER_H

#include <QObject>
#include <QTimer>

/*!
 * \brief The SPermissionsController class checks camera permissions on timer timeout.
 *        It is mostly used for iPhone devices to request camera permission and then
 *        emit signal to set Camera to SBarCodeScanner.
 */
class SPermissionsController : public QObject
{
    Q_OBJECT
public:
    explicit SPermissionsController(QObject *parent = nullptr);

public slots:
    /*!
     * \fn void checkPermissions()
     * \brief Checks camera permission.
     */
    void checkPermissions();

signals:
    /*!
     * \brief This signal is emitted when camera permission is granted.
     */
    void cameraPermissionGranted();

private:
    QTimer* m_timer = nullptr;
};

#endif // SPERMISSIONSCONTROLLER_H
