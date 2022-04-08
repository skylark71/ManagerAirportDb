#ifndef VALIDATORS_H
#define VALIDATORS_H

#include <QValidator>

namespace Validators
{
    const QRegularExpressionValidator loginValidator(QRegularExpression("^\\w{5,20}$"));
    const QRegularExpressionValidator passwordValidator(QRegularExpression("^\\w{5,20}$"));
    const QRegularExpressionValidator surnameValidator(QRegularExpression("^[А-Я][а-я]+$"));
    const QRegularExpressionValidator nameValidator(QRegularExpression("^[А-Я][а-я]+$"));
    const QRegularExpressionValidator midnameValidator(QRegularExpression("^([А-Я][а-я]+)?$"));
    const QRegularExpressionValidator passportSerialValidator(QRegularExpression("^\\d{4,4}$"));
    const QRegularExpressionValidator passportNumberValidator(QRegularExpression("^\\d{6,6}$"));
    const QRegularExpressionValidator departurePointValidator(QRegularExpression("^[гспд]\\.\\s[А-Я]([а-я]|-)+$"));
    const QRegularExpressionValidator arrivalPointValidator(QRegularExpression("^[гспд]\\.\\s[А-Я]([а-я]|-)+$"));
    const QRegularExpressionValidator markValidator(QRegularExpression("^\\S+$"));
}

#endif // VALIDATORS_H
