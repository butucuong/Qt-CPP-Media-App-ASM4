#include "translation.h"
#include <QDebug>
Translation::Translation( QGuiApplication *app)

{
    m_app=app;
    translator1= new QTranslator();
    translator2 = new QTranslator();
    translator3 = new QTranslator();
    translator1->load("string_us",":/translator");
    translator2->load("string_vn",":/translator");
    translator3->load("string_jp",":/translator");
}

QString Translation::emptyString()
{
    return "";
}

QString Translation::currentLanguage()
{
    return m_currentLanguage;
}

void Translation::setCurrentLanguage(QString language)
{
    m_currentLanguage=language;
    if(0==language.compare("us")){
        m_app->installTranslator(translator1);
            }
    if(0==language.compare("vi")){
        m_app->installTranslator(translator2);
    }
    if(0==language.compare("jp")){
        m_app->installTranslator(translator3);
    }
}

void Translation::selectLanguage(QString language)
{
    setCurrentLanguage(language);
    emit languageChanged();
}
