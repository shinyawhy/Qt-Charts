#include <QApplication>
#include <QMainWindow>
#include <QChartView>
#include <QChart>
#include <QBarSeries>
#include <QBarSet>
#include <QLineSeries>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QValueAxis>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QBarSet *set0 = new QBarSet("RareAtom_BarSet");
    QBarSet *set1 = new QBarSet("Tyloo_BarSet");
    QBarSet *set2 = new QBarSet("FazeClan_BarSet");
    QBarSet *set3 = new QBarSet("NAVI_BarSet");
    QBarSet *set4 = new QBarSet("Vitality_BarSet");

    *set0 << 1 << 2 << 3 << 4 << 5 << 6;
    *set1 << 5 << 3 << 2 << 4 << 4 << 7;
    *set2 << 3 << 5 << 8 << 13 << 8 << 5;
    *set3 << 5 << 6 << 7 << 3 << 4 << 5;
    *set4 << 9 << 7 << 5 << 3 << 1 << 2;

    set0->setColor(QColor("#a76283"));
    set1->setColor(QColor("#6e9bc5"));
    set2->setColor(QColor("#ebeee8"));
    set3->setColor(QColor("#fedc5e"));
    set4->setColor(QColor("#d9883d"));

    QBarSeries *barseries = new QBarSeries();
    barseries->append(set0);
    barseries->append(set1);
    barseries->append(set2);
    barseries->append(set3);
    barseries->append(set4);


    QLineSeries *lineseries = new QLineSeries();
    lineseries->setName("trend");
    lineseries->append(QPoint(0, 4));
    lineseries->append(QPoint(1, 15));
    lineseries->append(QPoint(2, 20));
    lineseries->append(QPoint(3, 4));
    lineseries->append(QPoint(4, 12));
    lineseries->append(QPoint(5, 17));

    QChart *chart = new QChart();
    chart->addSeries(barseries);
    chart->addSeries(lineseries);
    chart->setTitle("折线图和条形图");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(QStringList()<<"2019柏林"<<"2020RMR"<<"2021斯德哥尔摩"<<"2022安特卫普"<<"2022里约"<<"2023巴黎");
    axisX->setRange(QString("2019柏林"), QString("2023巴黎"));
    chart->addAxis(axisX, Qt::AlignBottom);


    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 20);
    chart->addAxis(axisY, Qt::AlignLeft);


    barseries->attachAxis(axisX);
    lineseries->attachAxis(axisX);


    barseries->attachAxis(axisY);
    lineseries->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(420, 300);
    window.show();

    return a.exec();
}
