#pragma once

#include <QByteArray>
#include <QObject>

#if !(defined(Q_OS_MACOS) || defined(Q_OS_WIN))
#include <QtDBus/QDBusAbstractAdaptor>
#endif

class QPixmap;
class QRect;
class QDBusMessage;
class QDBusConnection;
class TrayIcon;
class CaptureWidget;

#if !defined(DISABLE_UPDATE_CHECKER)
class QNetworkAccessManager;
class QNetworkReply;
class QVersionNumber;
#endif

class ShotupDaemon : public QObject
{
    Q_OBJECT
public:
    static void start();
    static ShotupDaemon* instance();
    static void createPin(const QPixmap& capture, QRect geometry);
    static void copyToClipboard(const QPixmap& capture);
    static void copyToClipboard(const QString& text,
                                const QString& notification = "");
    static bool isThisInstanceHostingWidgets();

    void sendTrayNotification(
      const QString& text,
      const QString& title = QStringLiteral("Shotup Info"),
      const int timeout = 5000);

#if defined(USE_KDSINGLEAPPLICATION) &&                                        \
  (defined(Q_OS_MACOS) || defined(Q_OS_WIN))
public slots:
    void messageReceivedFromSecondaryInstance(const QByteArray& message);
#endif

#if !defined(DISABLE_UPDATE_CHECKER)
public:
    void showUpdateNotificationIfAvailable(CaptureWidget* widget);

public slots:
    void checkForUpdates();
    void getLatestAvailableVersion();

private slots:
    void handleReplyCheckUpdates(QNetworkReply* reply);

signals:
    void newVersionAvailable(QVersionNumber version);
#endif

private:
    ShotupDaemon();
    void quitIfIdle();
    void attachPin(const QPixmap& pixmap, QRect geometry);
    void attachScreenshotToClipboard(const QPixmap& pixmap);

    void attachPin(const QByteArray& data);
    void attachScreenshotToClipboard(const QByteArray& screenshot);
    void attachTextToClipboard(const QString& text,
                               const QString& notification);

    void initTrayIcon();
    void enableTrayIcon(bool enable);

#if !(defined(Q_OS_MACOS) || defined(Q_OS_WIN))
    static QDBusMessage createMethodCall(const QString& method);
    static void checkDBusConnection(const QDBusConnection& connection);
    static void call(const QDBusMessage& m);
#endif

    bool m_persist;
    bool m_hostingClipboard;
    bool m_clipboardSignalBlocked;
    QList<QWidget*> m_widgets;
    TrayIcon* m_trayIcon;

#if !defined(DISABLE_UPDATE_CHECKER)
    QString m_appLatestUrl;
    QString m_appLatestVersion;
    bool m_showCheckAppUpdateStatus;
    QNetworkAccessManager* m_networkCheckUpdates;
#endif

    static ShotupDaemon* m_instance;

#if !(defined(Q_OS_MACOS) || defined(Q_OS_WIN))
    friend class ShotupDBusAdapter;
#endif
};
