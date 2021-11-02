#ifndef TRANSLATION_H
#define TRANSLATION_H
#include <QObject>
#include <QTranslator>
#include <QGuiApplication>

class Translation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString emptyString READ emptyString NOTIFY languageChanged)
    Q_PROPERTY(QString language READ currentLanguage NOTIFY languageChanged)
public:
    Translation( QGuiApplication *app);
    QString emptyString();
    QString currentLanguage();
    void setCurrentLanguage(QString language);
    Q_INVOKABLE void selectLanguage(QString language);

signals:
    void languageChanged();
private:
    QTranslator *translator1;
    QTranslator *translator2;
    QTranslator *translator3;
    QGuiApplication *m_app;
    QString m_currentLanguage;
};

#endif // TRANSLATION_H
