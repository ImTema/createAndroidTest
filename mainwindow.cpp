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
    answersVLayout=new QVBoxLayout(ui->answersScrollAreaWidgetContents);
    //item->setSelected(true);
    ui->questionsListWidget->addItem(item);
    ui->questionsListWidget->setCurrentItem(item);
    addQuestion(item->text());
    curQues=questions.value(item->text());
    curText=item->text();
    ui->numberOfQuestionsSpinBox->setMaximum(countQuestions-1);
    loadData();
    //ui->scrollArea_2->setLayout(answersVLayout);
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
    clearLayout();
    generateAnswers(index);
    generateAnswers(index);
}
void MainWindow::on_questionTextTextEdit_textChanged()
{
    QString textEdit=ui->questionTextTextEdit->toPlainText();
    qDebug()<<"changing question text"<<curText<<"to"<<textEdit;
    curQues->setText(textEdit);
}

void MainWindow::on_explanationTextTextEdit_textChanged()
{
    QString textEdit=ui->explanationTextTextEdit->toPlainText();
    curQues->setAnswerExplanation(textEdit);
}
void MainWindow::addQuestion(QString text){
    if(!questions.contains(text)){
        Question *q = new Question(text);
        questions.insert(text, q);
    }
    ui->numberOfQuestionsLabel->setText(QString::number(questions.count()));
}

void MainWindow::savenload(QString text)
{
    curQues->setAnswers(answers);
    saveData(curText, curQues);
    curQues=questions.value(text);
    curText=text;
    loadData();
}


void MainWindow::saveData(QString key, Question *value)
{

    qDebug()<<"saving data...";
    qDebug()<<"answers amount: "<<value->getAnswers().count();
    questions.insert(key, value);
}


void MainWindow::loadData()
{
    clearLayout();
    qDebug()<<"loading data...";
    answers=curQues->getAnswers();
    qDebug()<<"answers amount: "<<answers.count();
    if(!answers.isEmpty()){
        foreach(Answer *w, answers){
            answersVLayout->addWidget(w);//вылетает на смене вопроса на обратный после создания нового
        }
    }
    else{
        doingsAfterReselectingOrCreating();
    }
    ui->questionTypeComboBox->setCurrentIndex(curQues->getType());
    ui->questionTextTextEdit->setText(curQues->getQuestion());
    ui->explanationTextTextEdit->setText(curQues->getExplanation());
    setImageLabel(curQues->getFileName());

}

void MainWindow::on_questionsListWidget_clicked()
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

void MainWindow::on_compileTestButton_released()
{
    compileTest();
    qDebug()<<"Test compiled";
}

void MainWindow::clearLayout(){
    countAnswers=0;
    qDebug()<<"clearing layout. count: "<<answersVLayout->count();
    foreach(Answer* w, answers){
        qDebug()<<"deleting #"<<w->getId();
        delete w; //ука работает
    }
    answers.clear();
    qDebug()<<"clearing layout. count: "<<answersVLayout->count();
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
    countAnswers++;
    qDebug()<<"'answers amount after generating asnwers: "<<answers.count();
}

void MainWindow::generateCheckbox()
{
    Answer *ch = new Checkbox(ui->scrollAreaWidgetContents, answersVLayout, countAnswers);
    answers.insert(ch->getId(), ch);
}

void MainWindow::generateRadio()
{
    Answer *ch = new Radio(ui->scrollAreaWidgetContents, answersVLayout, countAnswers);
    answers.insert(ch->getId(), ch);
}

void MainWindow::generateSequence()
{
    Answer *ch = new Sequence(ui->scrollAreaWidgetContents, answersVLayout, countAnswers);
    answers.insert(ch->getId(), ch);
}

void MainWindow::generateMatching()
{
    Answer *ch = new Matching(ui->scrollAreaWidgetContents, answersVLayout, countAnswers);
    answers.insert(ch->getId(), ch);
}

void MainWindow::generateShort()
{
    Answer *ch = new Short(ui->scrollAreaWidgetContents, answersVLayout, countAnswers);
    answers.insert(ch->getId(), ch);
}

void MainWindow::on_insertImage_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Select an image"),
                                                "../Images/", tr("All images (*.jpg *jpeg *.bmp *.gif *.png)"));
    curQues->setFileName(file);
    setImageLabel(file);
}

void MainWindow::setImageLabel(QString file)
{

    QLabel *label=ui->imageLabel;
    qDebug()<<"filename:"<<file;
    if(file.isEmpty()){
        label->clear();
    }
    else{
        QSize size(100, 50);
        QPixmap pixmap(file);
        pixmap=pixmap.scaled(size, Qt::KeepAspectRatio);
        label->resize(pixmap.width(), pixmap.height());
        label->setPixmap(pixmap);
    }
}


void MainWindow::on_addQuestionButton_clicked()
{
    QListWidgetItem *item = new QListWidgetItem("Вопрос "+ QString::number(countQuestions));
    ui->questionsListWidget->addItem(item);
    ui->questionsListWidget->setCurrentItem(item);
    addQuestion(item->text());
    savenload(item->text());
    countQuestions++;
    ui->numberOfQuestionsSpinBox->setMaximum(countQuestions-1);
}

void MainWindow::on_addAnswerButton_released()
{
    generateAnswers(ui->questionTypeComboBox->currentIndex());
}


void MainWindow::on_falseOrderQuestion_toggled(bool checked)
{
    qDebug()<<checked;
    sets->setOrderedQuestions(checked);
}

void MainWindow::on_falseOrderAnswers_toggled(bool checked)
{
    qDebug()<<checked;
    sets->setOrderedAnswers(checked);
}

void MainWindow::on_numberOfQuestionsSpinBox_valueChanged(int arg1)
{
    qDebug()<<"number of questions"<<arg1;
    sets->setNumberOfQuestions(arg1);
}



void MainWindow::compileTest()
{
    QDomDocument doc("testItself");
    QDomElement domElement = doc.createElement("testItself");
    doc.appendChild(domElement);
    QDomElement settings2write =
            getSettings(doc
                        //, "", "", ""
                        );
    domElement.appendChild(settings2write);
    QFile file("exampleTest.xml");
    if(file.open(QIODevice::WriteOnly)) {
        QTextStream(&file) << doc.toString();
        file.close();
    }
}

void MainWindow::doingsAfterReselectingOrCreating()
{
    generateAnswers(ui->questionTypeComboBox->currentIndex());
    generateAnswers(ui->questionTypeComboBox->currentIndex());
}

QDomElement MainWindow::getSettings( QDomDocument& domDoc
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


QDomElement MainWindow::makeElement( QDomDocument& domDoc,
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
