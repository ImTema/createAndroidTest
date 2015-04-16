#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    countQuestions=2;
    countAnswers=0;
    //qDebug()<<"";
    QListWidgetItem *item = new QListWidgetItem("Вопрос 1");
    //item->setSelected(true);
    ui->questionsListWidget->addItem(item);
    ui->questionsListWidget->setCurrentItem(item);
    addQuestion(item->text());
    curQues=questions.value(item->text());
    curText=item->text();
    loadData();
    generateAnswers(ui->questionTypeComboBox->currentIndex());
    //connect(signalMapper, SIGNAL(mapped(int)), this, SIGNAL(objectNameChanged(QString)));
//    ui->radioButton->setCheckable(true);//orderedQuestion
//    ui->radioButton->setChecked(true);
//    ui->radioButton_5->setCheckable(true);//orderedAnswer
//    ui->radioButton_5->setChecked(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_deleteQuestionButton_clicked()
{
    int currentRow=ui->questionsListWidget->currentRow();
    curQues=questions.value(ui->questionsListWidget->item(currentRow+1)->text());
    curText=ui->questionsListWidget->item(currentRow+1)->text();
    loadData();
    for(int i=currentRow; i<countQuestions-2; i++){
        QListWidgetItem* curItem=ui->questionsListWidget->item(i);
        qDebug()<<"current"<<curItem->text();
        QListWidgetItem* nextItem=ui->questionsListWidget->item(i+1);
        saveData(curItem->text(), questions.value(nextItem->text()));
    }
    countQuestions--;
    ui->questionsListWidget->takeItem(countQuestions-1);
    curQues=questions.value(ui->questionsListWidget->item(currentRow)->text());
    curText=ui->questionsListWidget->item(currentRow)->text();
    //delete itm1;
}

void MainWindow::on_questionTypeComboBox_activated(int index)
{
    qDebug()<<"setting question type"<<index;
    curQues->setType(index);
    clearLayout(*ui->answersVLayout);
    ui->answersVLayout->update();
    qDebug()<<"new count: "<<ui->answersVLayout->count();
    generateAnswers(index);
    generateAnswers(index);
}
void MainWindow::on_questionTextTextEdit_textChanged()
{
    QString textEdit=ui->questionTextTextEdit->toPlainText();
    qDebug()<<"changing question"<<curText<<"text to "<<textEdit;
    qDebug()<<ui->questionTextTextEdit->sizePolicy();

    curQues->setText(textEdit);
}

void MainWindow::on_explanationTextTextEdit_textChanged()
{
        QString textEdit=ui->explanationTextTextEdit->toPlainText();
       qDebug()<<"changing explanation "<<curText<<" to "<<textEdit;
       curQues->setAnswerExplanation(textEdit);
}
void MainWindow::addQuestion(QString text){
    if(!questions.contains(text)){
        Question *q = new Question(text);
        questions.insert(text, q);
    }
    qDebug()<<questions.keys();
//    qDebug()<<"THIS IS LIST: "<<questions.count();
//    foreach(QString s, questions.keys()){
//        qDebug()<<s<<":"<<questions.value(s)->getQuestion();
//    }
//    qDebug()<<"";
    ui->numberOfQuestionsLabel->setText(QString::number(questions.count()));
}


void MainWindow::loadData()
{
    ui->questionTypeComboBox->setCurrentIndex(curQues->getType());
    ui->questionTextTextEdit->setText(curQues->getQuestion());
    ui->explanationTextTextEdit->setText(curQues->getExplanation());
}

void MainWindow::saveData(QString key, Question *value)
{
    questions.insert(key, value);
}

void MainWindow::savenload(QString text)
{
    saveData(curText, curQues);
    curQues=questions.value(text);
    curText=text;
    loadData();
}



void MainWindow::on_questionsListWidget_clicked(
        //const QModelIndex &index
        )
{
    QListWidgetItem *item=ui->questionsListWidget->currentItem();
    qDebug()<<"activated item: text "<<item->text();
    savenload(item->text());
}

void MainWindow::on_limitedTimeTimeEdit_timeChanged(const QTime &time)
{
    qDebug()<<time.toString();
    sets->setLimitedTime(time);
}

//void MainWindow::on_trueOrderedAnswers_toggled(bool checked)
//{

//    sets->setOrderedAnswers(checked);
//    qDebug()<<sets->getOrderedAnswers();
//}

//void MainWindow::on_trueOrderedQuestions_toggled(bool checked)
//{
//    sets->setOrderedQuestions(checked);
//    qDebug()<<sets->getOrderedQuestions();
//}

//void MainWindow::on_trueOrderedQuestions_clicked(bool checked)
//{
//    sets->setOrderedAnswers(checked);
//    qDebug()<<sets->getOrderedAnswers();
//}


//void MainWindow::on_falseOrderedQuestions_clicked()
//{

//}



//QDomElement makeElement( QDomDocument& domDoc,
//                         const QString& strName,
//                         const QString& strAttr = QString(),
//                         const QString& strText = QString(),

//        );
QDomElement makeElement( QDomDocument& domDoc,
                         const QString& strName,
                         const QString& strText = QString(),
                         const QString& strAttr = QString(),
                         const QString& strAttrValue = QString()
        );



void MainWindow::on_compileTestButton_released()
{
    compileTest();
    qDebug()<<"Test compiled";
}




void MainWindow::compileTest()
{
    QDomDocument doc("testItself");
    QDomElement domElement = doc.createElement("testItself");
    doc.appendChild(domElement);
    QDomElement sets =
            settings(doc
                     //, "", "", ""
                     );
    domElement.appendChild(sets);
    QFile file("exampleTest.xml");
    if(file.open(QIODevice::WriteOnly)) {
        QTextStream(&file) << doc.toString();
        file.close();
    }
}



void MainWindow::clearLayout(QLayout& layout){
    countAnswers=0;
    qDebug()<<"clearing layout. count: "<<layout.count();
    QLayoutItem *item;
    while(!ui->answersVLayout->isEmpty()){
        item=ui->answersVLayout->takeAt(0);
        delete item;
        ui->answersVLayout->removeItem(item);
    }
    qDebug()<<"layoutCleared";
}



void MainWindow::generateAnswers(int index)
{
    switch(index){
    case 0://Polar
        generateRadio();
        break;
    case 1://One of many
        generateRadio();
        break;
    case 2://many of many
        generateCheckbox();
        break;
    case 3://matching
        generateMatching();
                break;
    case 4://sequence
        generateSequence();
        break;
    case 5://short
        generateShort();
        break;
    }
}



void MainWindow::generateCheckbox()
{
    QLineEdit *answerText=new QLineEdit();
    //answerText->setAccessibleDescription("answer"+countAnswers);
    QCheckBox *correctCheckbox=new QCheckBox("Правильный");
    QSpinBox *answerPrice=new QSpinBox();
    QLabel *priceLabel = new QLabel("Стоимость");
    //QPushButton *deleteAnswerButton=new QPushButton("Удалить");
    QHBoxLayout *answer = new QHBoxLayout();
    answerPrice->setMaximum(10);
    answer->addWidget(answerText);
    answer->addWidget(correctCheckbox);
    answer->addWidget(answerPrice);
    answer->addWidget(priceLabel);
    //answer->addWidget(deleteAnswerButton);
    ui->answersVLayout->addLayout(answer);
    countAnswers++;
    //qDebug()<<"accessible name"<<answerText->accessibleDescription();
    //QObject::connect(answerText, SIGNAL(textChanged(QString)), this, SLOT(on_answerText_textChanged(QString)));
}
void MainWindow::generateRadio()
{
    QLineEdit *answerText=new QLineEdit();
    QRadioButton *correctCheckbox=new QRadioButton("Правильный");
    QSpinBox *answerPrice=new QSpinBox();
    QLabel *priceLabel = new QLabel("Стоимость");
    //QPushButton *deleteAnswerButton=new QPushButton("Удалить");
    QHBoxLayout *answer = new QHBoxLayout();
    answerPrice->setMaximum(10);
    answer->addWidget(answerText);
    answer->addWidget(correctCheckbox);
    answer->addWidget(answerPrice);
    answer->addWidget(priceLabel);

    //answer->addWidget(deleteAnswerButton);
    ui->answersVLayout->addLayout(answer);
    countAnswers++;
    QObject::connect(answerText, SIGNAL(textChanged(QString)), this, SLOT(on_answerText_textChanged(QString)));
}

void MainWindow::generateSequence()
{
    QLineEdit *answerText=new QLineEdit();
    //QPushButton *deleteAnswerButton=new QPushButton("Удалить");
    QHBoxLayout *answer = new QHBoxLayout();
    QLabel *sequenceNumber= new QLabel(QString::number(countAnswers+1));
    answer->addWidget(sequenceNumber);
    answer->addWidget(answerText);
    //answer->addWidget(deleteAnswerButton);
    ui->answersVLayout->addLayout(answer);
    countAnswers++;
}

void MainWindow::generateMatching()
{
    QLineEdit *answerText=new QLineEdit();
    QLineEdit *answerText2=new QLineEdit();
    QRadioButton *correctCheckbox=new QRadioButton("Правильный");
    QSpinBox *answerPrice=new QSpinBox();
    QLabel *priceLabel = new QLabel("Стоимость");
    //QPushButton *deleteAnswerButton=new QPushButton("Удалить");
    QHBoxLayout *answer = new QHBoxLayout();
    answerPrice->setMaximum(10);
    answer->addWidget(answerText);
    answer->addWidget(new QLabel(" - "));
    answer->addWidget(answerText2);
    answer->addWidget(correctCheckbox);
    answer->addWidget(answerPrice);
    answer->addWidget(priceLabel);
    //answer->addWidget(deleteAnswerButton);
    ui->answersVLayout->addLayout(answer);
    countAnswers++;
}

void MainWindow::generateShort()
{
    QLineEdit *answerText=new QLineEdit();
    //QPushButton *deleteAnswerButton=new QPushButton("Удалить");
    QHBoxLayout *answer = new QHBoxLayout();
    answer->addWidget(answerText);
    //answer->addWidget(deleteAnswerButton);
    ui->answersVLayout->addLayout(answer);
    countAnswers++;
}




QDomElement MainWindow::settings( QDomDocument& domDoc
                     //const QString& strName,
                     //const QString& strPhone,
                     //const QString& strEmail
                     )
{
    QDomElement domElement = makeElement(domDoc, "globalSettings");
    domElement.appendChild(makeElement(domDoc, "name", "testName"));
    domElement.appendChild(makeElement(domDoc, "questionsToAsk", "3"));
    domElement.appendChild(makeElement(domDoc, "randomizeQuestions", "yes"));
    domElement.appendChild(makeElement(domDoc, "randomizeAnswers", "yes"));
    domElement.appendChild(makeElement(domDoc, "timeLimit", QTime(0,0,30,0).toString()));
    domElement.appendChild(makeElement(domDoc, "gradeSystem"));
    return domElement;
}

QDomElement makeElement( QDomDocument& domDoc,
                         const QString& strName,
                         const QString& strText,
                         const QString& strAttr,
                         const QString& strAttrValue
        )
{
    QDomElement domElement = domDoc.createElement(strName);
    if (!strAttrValue.isEmpty()) {
        QDomAttr domAttr = domDoc.createAttribute(strAttr);
        domAttr.setValue(strAttrValue);
        domElement.setAttributeNode(domAttr);
    }
    if (!strText.isEmpty()) {
        QDomText domText = domDoc.createTextNode(strText);
        domElement.appendChild(domText);
    }
    return domElement;
}

//void MainWindow::on_radioButton_4_toggled(bool checked)
//{
//    qDebug()<<checked;
//}

//void MainWindow::on_radioButton_5_toggled(bool checked)
//{
//    qDebug()<<checked;
//}

void MainWindow::on_trueOrderedQuestions_toggled(bool checked)
{
    qDebug()<<checked;
    sets->setOrderedQuestions(checked);
}


void MainWindow::on_answerText_textChanged(const QString &s)
{
    qDebug()<<"answer"<<s;
}

void MainWindow::on_insertImage_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Select an image"),
                                     "../Images/", tr("All images (*.jpg *jpeg *.bmp *.gif *.png)"));
//       QUrl Uri ( QString ( "file://%1" ).arg ( file ) );
//       QImage image = QImageReader ( file ).read();

//       QTextDocument * textDocument = ui->questionTextTextEdit->document();
//       textDocument->addResource( QTextDocument::ImageResource, Uri, QVariant ( image ) );
//       QTextCursor cursor = ui->questionTextTextEdit->textCursor();
//       QTextImageFormat imageFormat;
//       imageFormat.setWidth( image.width() );
//       imageFormat.setHeight( image.height() );
//       imageFormat.setName( Uri.toString() );
//       cursor.insertImage(imageFormat);

       QPixmap pixmap(file);
       QLabel *label=ui->imageLabel;
       QSize size(100, 50);
       pixmap=pixmap.scaled(size, Qt::KeepAspectRatio);
       label->resize(pixmap.width(), pixmap.height());
       label->setPixmap(pixmap);

       label->show();
}
void MainWindow::on_addQuestionButton_clicked()
{
    QListWidgetItem *item = new QListWidgetItem("Вопрос "+ QString::number(countQuestions));
    ui->questionsListWidget->addItem(item);
    ui->questionsListWidget->setCurrentItem(item);
    addQuestion(item->text());
    savenload(item->text());
    countQuestions++;
}

void MainWindow::on_addAnswerButton_released()
{
    generateAnswers(ui->questionTypeComboBox->currentIndex());
}
