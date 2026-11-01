#ifndef BOTMODEL_H
#define BOTMODEL_H

#include <QObject>
#include <QList>
#include <QString>

struct InstanceInfo {
    QString name;
    QString version;
    QString path;
    bool installed;
    // Add more instance fields as needed
};

class BotModel : public QObject
{
    Q_OBJECT
public:
    explicit BotModel(QObject *parent = nullptr);
    ~BotModel();

    // Connection management
    void connectToBot(const QString &host, quint16 port, const QString &username, const QString &auth);
    void disconnectBot();
    
    // Instance management
    void launchInstance(const QString &instanceName);
    void addNewInstance();
    
    QList<InstanceInfo> instances() const;
    void setInstances(const QList<InstanceInfo> &instances);
    
    bool isConnected() const;
    void setConnected(bool connected);
    
    bool isRunning() const;
    void setRunning(bool running);
    
    QString selectedInstanceName() const;
    void setSelectedInstanceName(const QString &name);
    
    // Get instance by name
    InstanceInfo instance(const QString &name) const;

signals:
    void connectionRequested(const QString &host, quint16 port, const QString &username, const QString &auth);
    void botDisconnected();
    void instanceLaunchRequested(const QString &instanceName);
    void addInstanceRequested();
    void instancesChanged();
    void connectedChanged();
    void runningChanged();
    void selectedInstanceNameChanged();

public slots:
    // Slots for QML interaction
    void slotConnect(const QString &host, quint16 port, const QString &username, const QString &auth);
    void slotDisconnect();
    void slotLaunch(const QString &instanceName);
    void slotAddInstance();

private:
    QList<InstanceInfo> m_instances;
    bool m_connected;
    bool m_running;
    QString m_selectedInstanceName;
};

#endif // BOTMODEL_H