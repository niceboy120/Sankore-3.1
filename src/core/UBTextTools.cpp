#include <QDebug>
#include "UBTextTools.h"

QString UBTextTools::cleanHtmlCData(const QString &_html){

    QString clean = "";
    QByteArray content = _html.toAscii();
    const char* rawDatas = content.constData();

    for(int i=0; i<content.size(); i++){
        if(0x0 != (void*)rawDatas[i]){
            clean += rawDatas[i];
        }
    }

    return clean;
}


QString UBTextTools::cleanHtml(const QString& _html){
    const QString START_TAG = "<!doctype";
    const QString END_TAG = "</html";

    QString cleanSource = "";
    QString simplifiedHtml = _html;

    int start = simplifiedHtml.toLower().indexOf(START_TAG);
    int end = simplifiedHtml.toLower().indexOf(END_TAG) + END_TAG.size();

    cleanSource = simplifiedHtml.mid(start, end);

    return cleanSource;
}