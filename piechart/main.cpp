#include <QApplication>
#include <QMainWindow>
#include <QChartView>
#include <QChart>
#include <QPieSeries>
#include <QPieSlice>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPieSeries *series = new QPieSeries();
    series->append("rareatom", 3);
    series->append("tyloo", 1);
    series->append("navi", 7);
    series->append("faze", 5);
    series->append("g2", 4);

    QPieSlice *slice = series->slices().at(1);
    slice->setExploded(true);
    slice->setLabelVisible(true);
    slice->setPen(QPen(Qt::red, 2));
    slice->setBrush(Qt::yellow);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("饼状图");
    chart->legend()->setVisible(true);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(420, 300);
    window.show();

    return a.exec();
}
