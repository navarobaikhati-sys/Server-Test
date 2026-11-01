#include "botmodel.h"
#include <QDebug>

BotModel::BotModel(QObject *parent)
    : QObject(parent)
    , m_connected(false)
    , m_running(false)
{
}

BotModel::~BotModel() = default;

void BotModel::connectToBot(const QString &host, quint16 port, const QString &username, const QString &auth)
{
    qDebug() << "BotModel: Attempting to connect to" << host << port << username;
    // Emit signal that connection was attempted
    emit connectionRequested(host, port, username, auth);
}

void BotModel::disconnectBot()
{
    qDebug() << "BotModel: Disconnecting bot";
    emit botDisconnected();
}

void BotModel::launchInstance(const QString &instanceName)
{
    qDebug() << "BotModel: Launching instance" << instanceName;
    emit instanceLaunchRequested(instanceName);
}

void BotModel::addNewInstance()
{
    qDebug() << "BotModel: Add new instance requested";
    emit addInstanceRequested();
}

QList<InstanceInfo> BotModel::instances() const
{
    return m_instances;
}

void BotModel::setInstances(const QList<InstanceInfo> &instances)
{
    m_instances = instances;
    emit instancesChanged();
}

bool BotModel::isConnected() const
{
    return m_connected;
}

void BotModel::setConnected(bool connected)
{
    m_connected = connected;
    emit connectedChanged();
}

bool BotModel::isRunning() const
{
    return m_running;
}

void BotModel::setRunning(bool running)
{
    m_running = running;
    emit runningChanged();
}

QString BotModel::selectedInstanceName() const
{
    return m_selectedInstanceName;
}

void BotModel::setSelectedInstanceName(const QString &name)
{
    m_selectedInstanceName = name;
    emit selectedInstanceNameChanged();
}

// Getter for specific instance by name
InstanceInfo BotModel::instance(const QString &name) const
{
    for (const auto &inst : m_instances) {
        if (inst.name == name) {
            return inst;
        }
    }
    return InstanceInfo{};
}

// Signal implementations
void BotModel::connectionRequested(const QString &host, quint16 port, const QString &username, const QString &auth)
{
    Q_UNUSED(host)
    Q_UNUSED(port)
    Q_UNUSED(username)
    Q_UNUSED(auth)
    // Will be connected in the actual implementation
    qDebug() << "Connection requested signal emitted";
}

void BotModel::botDisconnected()
{
    qDebug() << "Bot disconnected signal emitted";
}

void BotModel::instanceLaunchRequested(const QString &instanceName)
{
    qDebug() << "Instance launch requested:" << instanceName;
}

void BotModel::addInstanceRequested()
{
    qDebug() << "Add instance requested signal emitted";
}

#include "moc_botmodel.cpp"