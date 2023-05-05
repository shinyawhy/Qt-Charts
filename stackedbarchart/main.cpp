#include <QApplication>
#include <QMainWindow>
#include <QChartView>
#include <QChart>
#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QLegend>
#include <QStackedBarSeries>

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

    QStackedBarSeries *series = new QStackedBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("简单垂直条形图");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(QStringList()<<"2019柏林"<<"2020RMR"<<"2021斯德哥尔摩"<<"2022安特卫普"<<"2022里约"<<"2023巴黎");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

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
