#include <QApplication>
#include <QMainWindow>
#include <QChartView>
#include <QChart>
#include <QSplineSeries>
#include <QValueAxis>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplineSeries *splineSeries = new QSplineSeries();

    splineSeries->setName("trend");
    splineSeries->append(QPoint(0, 4));
    splineSeries->append(QPoint(1, 15));
    splineSeries->append(QPoint(2, 20));
    splineSeries->append(QPoint(3, 4));
    splineSeries->append(QPoint(4, 12));
    splineSeries->append(QPoint(5, 17));

    // way2
    *splineSeries << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

    splineSeries->setPointsVisible(true);
    splineSeries->setPointLabelsVisible(true);
    splineSeries->setPointLabelsFormat("(@xPoint, @yPoint)");


    QChart *chart = new QChart();
    chart->addSeries(splineSeries);
    chart->legend()->setVisible(true);
    chart->setTitle("曲线图");
    chart->legend()->setAlignment(Qt::AlignBottom);

    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setRange(0, 20);
    chart->axes(Qt::Vertical).first()->setRange(-5, 25);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(420, 300);
    window.show();

    return a.exec();
}
