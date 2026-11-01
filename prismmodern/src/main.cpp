#include <QApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QScreen>
#include <QtGlobal>

#include "botmodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // Enable high DPI scaling
    Qt::AA_EnableHighDpiScaling;
    Qt::AA_UseHighDpiPixmaps;
    
    // Set application metadata
    app.setOrganizationName("PrismLauncher");
    app.setApplicationName("PrismModern");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationDomain("prismlauncher.org");
    
    // Create the model
    BotModel model;
    
    // Expose model to QML context
    QQmlContext *context = nullptr;
    
    QQmlApplicationEngine engine;
    
    // Set context property for context-wide access
    context = engine.rootContext();
    context->setContextProperty("botModel", &model);
    
    // Load the main QML file
    const QUrl url(u"qrc:/prismmodern_ui/qml/MainWindow.qml"_qs);
    
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) {
            qCritical() << "Failed to create QML object for URL:" << url;
            QCoreApplication::exit(-1);
        }
    }, Qt::QueuedConnection);
    
    engine.load(url);
    
    return app.exec();
}