#pragma once

#include <QObject>
#include <QScopedPointer>
#include <QLoggingCategory>

namespace ddc
{
Q_DECLARE_LOGGING_CATEGORY(deepinid_client)

class SyncClientPrivate;
class SyncClient: public QObject
{
Q_OBJECT
public:
    explicit SyncClient(QObject *parent = Q_NULLPTR);
    ~SyncClient() Q_DECL_OVERRIDE;

    QString machineID() const;
    void setSession();
    void cleanSession();

Q_SIGNALS:
    void prepareClose();
    void requestHide();
    void onLogin(const QString &sessionID,
                 const QString &clientID,
                 const QString &code,
                 const QString &state);
    void onCancel(const QString &clientID);

public Q_SLOTS:
    Q_SCRIPTABLE QString gettext(const QString &str);
    Q_SCRIPTABLE void authCallback(const QVariantMap &tokenInfo);
    Q_SCRIPTABLE void open(const QString &url);
    Q_SCRIPTABLE void close();

private:
    QScopedPointer<SyncClientPrivate> dd_ptr;
    Q_DECLARE_PRIVATE_D(qGetPtrHelper(dd_ptr), SyncClient)
};

}
