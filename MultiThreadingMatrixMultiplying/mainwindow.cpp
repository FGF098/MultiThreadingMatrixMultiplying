#include "mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget* parent)
	: generator()
{
	int m = 10;
	int n = 8;
	int p = 6;

	first_matrix = new MatrixInt({ m, n });
	second_matrix = new MatrixInt({ n, p });
	third_matrix = new MatrixInt({ m, p });

	int i, j;

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			(*first_matrix)[Coordinates(i, j)] = generator.rand(-10, 10);
	for (i = 0; i < n; i++)
		for (j = 0; j < p; j++)
			(*second_matrix)[Coordinates(i, j)] = generator.rand(-10, 10);

	MatrixInt::ClassicCycle(*first_matrix, *second_matrix, *third_matrix);

	ui.setupUi(this);

	ui.first_table->setRowCount(m);
	ui.first_table->setColumnCount(n);
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			ui.first_table->setItem(i, j, new QTableWidgetItem(QString::number((*first_matrix)[Coordinates(i, j)])));
	ui.first_table->resizeColumnsToContents();
	ui.first_table->resizeRowsToContents();

	ui.second_table->setRowCount(n);
	ui.second_table->setColumnCount(p);
	for (i = 0; i < n; i++)
		for (j = 0; j < p; j++)
			ui.second_table->setItem(i, j, new QTableWidgetItem(QString::number((*second_matrix)[Coordinates(i, j)])));
	ui.second_table->resizeColumnsToContents();
	ui.second_table->resizeRowsToContents();

	ui.result_table->setRowCount(m);
	ui.result_table->setColumnCount(p);
	for (i = 0; i < m; i++)
		for (j = 0; j < p; j++)
			ui.result_table->setItem(i, j, new QTableWidgetItem(QString::number((*third_matrix)[Coordinates(i, j)])));
	ui.result_table->resizeColumnsToContents();
	ui.result_table->resizeRowsToContents();

	update();
}