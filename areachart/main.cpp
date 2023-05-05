#include <QApplication>
#include <QMainWindow>
#include <QLineSeries>
#include <QChartView>
#include <QAreaSeries>
#include <QValueAxis>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QLineSeries *series0 = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();

    // *解引用
    *series0 << QPointF(1, 5) << QPointF(3, 7) << QPointF(7, 6) << QPointF(9, 7) << QPointF(12, 6)
             << QPointF(16, 7) << QPointF(18, 5);
    *series1 << QPointF(1, 3) << QPointF(3, 4) << QPointF(7, 3) << QPointF(8, 2) << QPointF(12, 3)
             << QPointF(16, 4) << QPointF(18, 3);

    QAreaSeries *series = new QAreaSeries(series0, series1);
    series->setName("BatMan");
    series->setPointLabelsVisible(true); // 显示点上的标签


    QPen pen(0xffee6f);
    pen.setWidth(3);
    series->setPen(pen);

    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));//线性渐变
    gradient.setColorAt(0.0, 0xfce38a);
    gradient.setColorAt(1.0, 0xf38181);
    gradient.setCoordinateMode(QGradient::ObjectMode);
    series->setBrush(gradient);


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("简单面积图示例");
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setRange(0, 20);
    chart->axes(Qt::Vertical).first()->setRange(0, 10);

    QValueAxis *axisY  = qobject_cast<QValueAxis*>(chart->axes(Qt::Vertical).first());
    Q_ASSERT(axisY);
    axisY->setLabelFormat("%.1f ");


    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);



    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
    return a.exec();
}
