#if !defined(_MSC_VER)
#define CODING_VS_CODE
#endif
#include <iostream>
#include <math.h>
#if !defined(CODING_VS_CODE)
	#include <clocale>
#endif
using namespace std;


// Завдання 1.6

class Diamond {
	double a;          // сторона
	double d1, d2;     // діагоналі
	unsigned int color; // колір
public:
	// Конструктори
	Diamond() : a(1.0), d1(1.0), d2(1.0), color(0) {}
	
	Diamond(double side, double diag1, double diag2) 
		: a(side), d1(diag1), d2(diag2), color(0) {
		validateParams();
	}
	
	Diamond(double side, double diag1, double diag2, int c)
		: a(side), d1(diag1), d2(diag2), color(c >= 0 ? c : 0) {
		validateParams();
	}
	
	// Геттери
	double getA() const { return a; }
	double getD1() const { return d1; }
	double getD2() const { return d2; }
	int getColor() const { return color; }
	
	// Сеттери з перевіркою
	void setA(double side) {
		if (side > 0 && side < 1.e+100) {
			a = side;
		} else {
			cout << " Error: invalid side value\n";
		}
	}
	
	void setD1(double diag) {
		if (diag > 0 && diag < 1.e+100) {
			d1 = diag;
		} else {
			cout << " Error: invalid diagonal 1 value\n";
		}
	}
	
	void setD2(double diag) {
		if (diag > 0 && diag < 1.e+100) {
			d2 = diag;
		} else {
			cout << " Error: invalid diagonal 2 value\n";
		}
	}
	
	void setColor(int c) {
		if (c >= 0 && c <= 10000) {
			color = c;
		} else {
			cout << " Error: invalid color value\n";
		}
	}
	
	// Обчислення площі: S = (d1 * d2) / 2
	double getArea() const {
		return (d1 * d2) / 2.0;
	}
	
	// Обчислення периметра: P = 4 * a
	double getPerimeter() const {
		return 4.0 * a;
	}
	
	// Валідація параметрів
	void validateParams() {
		if (a <= 0 || a >= 1.e+100) a = 1.0;
		if (d1 <= 0 || d1 >= 1.e+100) d1 = 1.0;
		if (d2 <= 0 || d2 >= 1.e+100) d2 = 1.0;
	}
	
	// Функція друку
	void printInfo() const {
		cout << "\n=== Diamond Info ===\n";
		cout << " Side (a) = " << a 
		     << " | Diagonal 1 (d1) = " << d1
		     << " | Diagonal 2 (d2) = " << d2
		     << " | Color = " << color << "\n";
		cout << " Perimeter = " << getPerimeter() 
		     << " | Area = " << getArea() << "\n";
	}
	
	// Логічне порівняння (менше за площею)
	bool isLessThan(const Diamond& other) const {
		return getArea() < other.getArea();
	}
	
	// Логічне порівняння (рівні за площею)
	bool isEqual(const Diamond& other) const {
		return fabs(getArea() - other.getArea()) < 1.e-10;
	}
};

int mainExample1_6() {
	cout << "\n===== Testing Diamond Class (Task 1.6) =====\n";
	
	// Тестування конструкторів
	Diamond d1;
	cout << "Default constructor:\n";
	d1.printInfo();
	
	Diamond d2(5.0, 8.0, 6.0);
	cout << "\nConstructor with side and diagonals:\n";
	d2.printInfo();
	
	Diamond d3(4.0, 7.0, 5.0, 255);
	cout << "\nConstructor with side, diagonals and color:\n";
	d3.printInfo();
	
	// Тестування сеттерів з перевіркою
	cout << "\n--- Testing setters with validation ---\n";
	d1.setA(10.0);
	d1.setD1(12.0);
	d1.setD2(8.0);
	d1.setColor(100);
	cout << "After setting valid values:\n";
	d1.printInfo();
	
	// Спроба встановити невалідні значення
	cout << "\n--- Testing invalid values ---\n";
	d1.setA(-5);
	d1.setD1(0);
	d1.setD2(1.e+101);
	d1.setColor(-10);
	d1.setColor(10001);
	cout << "After attempting invalid values (should see error messages):\n";
	d1.printInfo();
	
	// Тестування логічних порівнянь
	cout << "\n--- Testing logical comparisons ---\n";
	cout << "Diamond d2 area = " << d2.getArea() << "\n";
	cout << "Diamond d3 area = " << d3.getArea() << "\n";
	
	if (d2.isLessThan(d3)) {
		cout << "d2 has smaller area than d3\n";
	} else if (d3.isLessThan(d2)) {
		cout << "d3 has smaller area than d2\n";
	} else {
		cout << "d2 and d3 have approximately equal areas\n";
	}
	
	// Порівняння на рівність
	Diamond d4(4.0, 7.0, 5.0, 128);
	if (d3.isEqual(d4)) {
		cout << "d3 and d4 have equal areas\n";
	}
	
	cout << "\n===== End of Diamond Class Testing =====\n";
	return 1;
}


// Завдання 2.6

enum STATE3D {
	OK_3D, BAD_INIT_3D, BAD_DIV_3D
};

class Vector3D {
	float x, y, z;
	int state;
	static int count;
public:
	// Конструктори
	Vector3D() : x(0.0f), y(0.0f), z(0.0f), state(OK_3D) { count++; }
	
	Vector3D(float val) : x(val), y(val), z(val), state(OK_3D) { count++; }
	
	Vector3D(float ix, float iy, float iz) : x(ix), y(iy), z(iz), state(OK_3D) { count++; }
	
	Vector3D(float* v) {
		if (v == nullptr) {
			state = BAD_INIT_3D;
			x = 0.0f; y = 0.0f; z = 0.0f;
		} else {
			x = v[0]; y = v[1]; z = v[2];
			state = OK_3D;
		}
		count++;
	}
	
	// Конструктор копій
	Vector3D(const Vector3D& s) : x(s.x), y(s.y), z(s.z), state(s.state) { count++; }
	
	// Оператор присвоєння
	Vector3D& operator=(const Vector3D& s) {
		if (this != &s) {
			x = s.x; y = s.y; z = s.z;
			state = s.state;
		}
		return *this;
	}
	
	// Деструктор
	~Vector3D() {
		count--;
		cout << " Vector3D destroyed. State: " << state << "\n";
	}
	
	// Геттери
	float getX() const { return x; }
	float getY() const { return y; }
	float getZ() const { return z; }
	int getState() const { return state; }
	float getElement(int index) const {
		if (index == 0) return x;
		if (index == 1) return y;
		if (index == 2) return z;
		return 0.0f;
	}
	
	// Сеттери
	void setX(float val) { x = val; }
	void setY(float val) { y = val; }
	void setZ(float val) { z = val; }
	
	// Функція друку
	void Output() const {
		cout << " [ " << x << ", " << y << ", " << z << " ] State: " << state << "\n";
	}
	
	// Функція введення
	void Input() {
		cout << " Input x, y, z: ";
		cin >> x >> y >> z;
	}
	
	// Додавання векторів
	Vector3D Add(const Vector3D& v) const {
		Vector3D tmp;
		tmp.x = x + v.x;
		tmp.y = y + v.y;
		tmp.z = z + v.z;
		return tmp;
	}
	
	// Віднімання векторів
	Vector3D Sub(const Vector3D& v) const {
		Vector3D tmp;
		tmp.x = x - v.x;
		tmp.y = y - v.y;
		tmp.z = z - v.z;
		return tmp;
	}
	
	// Множення на скаляр
	Vector3D Mul(float d) const {
		Vector3D tmp;
		tmp.x = x * d;
		tmp.y = y * d;
		tmp.z = z * d;
		return tmp;
	}
	
	// Ділення на скаляр (повертає short)
	short Div(float d) {
		if (fabs(d) < 1.e-25f) {
			state = BAD_DIV_3D;
			cout << " Error: Division by zero\n";
			return 0;
		}
		x /= d; y /= d; z /= d;
		return (short)1;
	}
	
	// Скалярний добуток
	float DotProduct(const Vector3D& v) const {
		return x * v.x + y * v.y + z * v.z;
	}
	
	// Довжина вектора
	float Length() const {
		return sqrt(x * x + y * y + z * z);
	}
	
	// Порівняння: більше за довжиною
	bool isGreaterThan(const Vector3D& v) const {
		return Length() > v.Length();
	}
	
	// Порівняння: менше за довжиною
	bool isLessThan(const Vector3D& v) const {
		return Length() < v.Length();
	}
	
	// Порівняння: рівні за довжиною
	bool isEqual(const Vector3D& v) const {
		return fabs(Length() - v.Length()) < 1.e-5f;
	}
	
	// Статичні методи для підрахунку об'єктів
	static int getCount() { return count; }
};
int Vector3D::count = 0;

int mainExample2_6() {
	cout << "\n===== Testing Vector3D Class (Task 2.6) =====\n";
	
	// Конструктор без параметрів
	Vector3D v1;
	cout << "Default constructor:\n";
	v1.Output();
	cout << "Count: " << Vector3D::getCount() << "\n";
	
	Vector3D v2(5.0f);
	cout << "\nConstructor with single float parameter:\n";
	v2.Output();
	cout << "Count: " << Vector3D::getCount() << "\n";
	
	Vector3D v3(1.0f, 2.0f, 3.0f);
	cout << "\nConstructor with three parameters:\n";
	v3.Output();
	cout << "Count: " << Vector3D::getCount() << "\n";
	
	// Конструктор з вказівником
	float arr[] = { 2.0f, 3.0f, 4.0f };
	Vector3D v4(arr);
	cout << "\nConstructor with pointer:\n";
	v4.Output();
	
	// Конструктор з NULL вказівником
	Vector3D v5(nullptr);
	cout << "\nConstructor with nullptr (should set BAD_INIT):\n";
	v5.Output();
	
	// Конструктор копій
	Vector3D v6(v3);
	cout << "\nCopy constructor from v3:\n";
	v6.Output();
	cout << "Count: " << Vector3D::getCount() << "\n";
	
	v1 = v3;
	cout << "\nAfter assignment v1 = v3:\n";
	v1.Output();
	
	cout << "\n--- Testing arithmetic operations ---\n";
	Vector3D vAdd = v3.Add(v4);
	cout << "v3 + v4 = ";
	vAdd.Output();
	
	Vector3D vSub = v4.Sub(v3);
	cout << "v4 - v3 = ";
	vSub.Output();
	
	Vector3D vMul = v3.Mul(2.0f);
	cout << "v3 * 2.0 = ";
	vMul.Output();
	
	cout << "\nv3 dot product v4 = " << v3.DotProduct(v4) << "\n";
	cout << "Length of v3 = " << v3.Length() << "\n";
	cout << "Length of v4 = " << v4.Length() << "\n";
	
	// Ділення
	cout << "\n--- Testing division ---\n";
	Vector3D v7(4.0f, 8.0f, 12.0f);
	cout << "Before division: ";
	v7.Output();
	v7.Div(2.0f);
	cout << "After division by 2.0: ";
	v7.Output();
	
	v7.Div(0.0f);
	cout << "After attempting division by 0: ";
	v7.Output();
	
	// Тестування порівнянь
	cout << "\n--- Testing comparisons ---\n";
	if (v3.isGreaterThan(v4)) {
		cout << "v3 is greater than v4\n";
	} else if (v4.isGreaterThan(v3)) {
		cout << "v4 is greater than v3\n";
	} else if (v3.isEqual(v4)) {
		cout << "v3 and v4 are equal in length\n";
	}
	
	cout << "\nFinal count: " << Vector3D::getCount() << "\n";
	cout << "\n===== End of Vector3D Class Testing =====\n";
	
	return 1;
}

// Завдання 3.6

enum STATE_MATRIX {
	OK_M, BAD_ALLOC, BAD_INDEX, BAD_DIV_M
};

class Matrix2D {
	double** data;
	int rows, cols;
	int state;
	static int count;
public:
	// Конструктор без параметрів (2x2)
	Matrix2D() : rows(2), cols(2), state(OK_M) {
		allocate();
		initializeZero();
		count++;
	}
	
	// Конструктор з одним параметром (n x n)
	Matrix2D(int n) : rows(n), cols(n), state(OK_M) {
		if (n <= 0) { rows = cols = 2; }
		allocate();
		initializeZero();
		count++;
	}
	
	// Конструктор з трьома параметрами (n x m з ініціалізацією)
	Matrix2D(int n, int m, double value) : rows(n), cols(m), state(OK_M) {
		if (n <= 0 || m <= 0) { rows = cols = 2; }
		allocate();
		initializeValue(value);
		count++;
	}
	
	// Конструктор копій
	Matrix2D(const Matrix2D& s) : rows(s.rows), cols(s.cols), state(s.state) {
		allocate();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				data[i][j] = s.data[i][j];
			}
		}
		count++;
	}
	
	// Оператор присвоєння
	Matrix2D& operator=(const Matrix2D& s) {
		if (this != &s) {
			deallocate();
			rows = s.rows;
			cols = s.cols;
			state = s.state;
			allocate();
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					data[i][j] = s.data[i][j];
				}
			}
		}
		return *this;
	}
	
	// Деструктор
	~Matrix2D() {
		deallocate();
		count--;
		cout << " Matrix2D destroyed\n";
	}
	
	// Приватні допоміжні функції
private:
	void allocate() {
		try {
			data = new double*[rows];
			for (int i = 0; i < rows; i++) {
				data[i] = new double[cols];
			}
		} catch (...) {
			state = BAD_ALLOC;
			cout << " Error: Memory allocation failed\n";
			data = nullptr;
		}
	}
	
	void deallocate() {
		if (data != nullptr) {
			for (int i = 0; i < rows; i++) {
				if (data[i] != nullptr) {
					delete[] data[i];
				}
			}
			delete[] data;
			data = nullptr;
		}
	}
	
	void initializeZero() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				data[i][j] = 0.0;
			}
		}
	}
	
	void initializeValue(double value) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				data[i][j] = value;
			}
		}
	}
	
public:
	// Встановлення значення елемента
	void setElement(int i, int j, double value = 0.0) {
		if (i < 0 || i >= rows || j < 0 || j >= cols) {
			state = BAD_INDEX;
			cout << " Error: Index out of bounds\n";
			return;
		}
		data[i][j] = value;
	}
	
	// Отримання значення елемента
	double getElement(int i, int j) const {
		if (i < 0 || i >= rows || j < 0 || j >= cols) {
			cout << " Error: Index out of bounds\n";
			return 0.0;
		}
		return data[i][j];
	}
	
	// Геттери
	int getRows() const { return rows; }
	int getCols() const { return cols; }
	int getState() const { return state; }
	
	// Функція друку
	void Output() const {
		cout << " Matrix (" << rows << " x " << cols << "):\n";
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << " " << data[i][j];
			}
			cout << "\n";
		}
		cout << " State: " << state << "\n";
	}
	
	// Функція введення
	void Input() {
		cout << " Enter matrix elements:\n";
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << " [" << i << "][" << j << "]: ";
				cin >> data[i][j];
			}
		}
	}
	
	// Додавання матриць (тільки для однакових розмірів)
	Matrix2D Add(const Matrix2D& m) const {
		if (rows != m.rows || cols != m.cols) {
			cout << " Error: Matrix dimensions do not match\n";
			return Matrix2D();
		}
		Matrix2D tmp(rows, cols, 0.0);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				tmp.data[i][j] = data[i][j] + m.data[i][j];
			}
		}
		return tmp;
	}
	
	// Віднімання матриць
	Matrix2D Sub(const Matrix2D& m) const {
		if (rows != m.rows || cols != m.cols) {
			cout << " Error: Matrix dimensions do not match\n";
			return Matrix2D();
		}
		Matrix2D tmp(rows, cols, 0.0);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				tmp.data[i][j] = data[i][j] - m.data[i][j];
			}
		}
		return tmp;
	}
	
	// Множення на скаляр
	Matrix2D Mul(double scalar) const {
		Matrix2D tmp(rows, cols, 0.0);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				tmp.data[i][j] = data[i][j] * scalar;
			}
		}
		return tmp;
	}
	
	// Ділення на скаляр
	short Div(double scalar) {
		if (fabs(scalar) < 1.e-25) {
			state = BAD_DIV_M;
			cout << " Error: Division by zero\n";
			return 0;
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				data[i][j] /= scalar;
			}
		}
		return 1;
	}
	
	// Обчислення суми всіх елементів матриці
	double Sum() const {
		double sum = 0.0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				sum += data[i][j];
			}
		}
		return sum;
	}
	
	bool isGreaterThan(const Matrix2D& m) const {
		return Sum() > m.Sum();
	}
	
	bool isLessThan(const Matrix2D& m) const {
		return Sum() < m.Sum();
	}
	
	bool isEqual(const Matrix2D& m) const {
		return fabs(Sum() - m.Sum()) < 1.e-10;
	}
	
	static int getCount() { return count; }
};
int Matrix2D::count = 0;

int mainExample3_6() {
	cout << "\n===== Testing Matrix2D Class (Task 3.6) =====\n";
	
	// Конструктор без параметрів (2x2)
	Matrix2D m1;
	cout << "Default constructor (2x2):\n";
	m1.Output();
	cout << "Count: " << Matrix2D::getCount() << "\n";
	
	// Конструктор з одним параметром (3x3)
	Matrix2D m2(3);
	cout << "\nConstructor with single parameter (3x3):\n";
	m2.Output();
	cout << "Count: " << Matrix2D::getCount() << "\n";
	
	// Конструктор з трьома параметрами
	Matrix2D m3(2, 3, 5.0);
	cout << "\nConstructor with three parameters (2x3, value=5.0):\n";
	m3.Output();
	
	// Встановлення елементів
	cout << "\nSetting elements:\n";
	m1.setElement(0, 0, 1.0);
	m1.setElement(0, 1, 2.0);
	m1.setElement(1, 0, 3.0);
	m1.setElement(1, 1, 4.0);
	cout << "After setting:\n";
	m1.Output();
	
	// Конструктор копій
	Matrix2D m4(m1);
	cout << "\nCopy constructor from m1:\n";
	m4.Output();
	cout << "Count: " << Matrix2D::getCount() << "\n";
	
	// Оператор присвоєння
	Matrix2D m5(2, 2, 0.0);
	m5 = m1;
	cout << "\nAfter assignment m5 = m1:\n";
	m5.Output();
	
	// Тестування арифметичних операцій
	cout << "\n--- Testing arithmetic operations ---\n";
	Matrix2D mAdd = m1.Add(m4);
	cout << "m1 + m4:\n";
	mAdd.Output();
	
	Matrix2D mSub = m4.Sub(m1);
	cout << "\nm4 - m1:\n";
	mSub.Output();
	
	Matrix2D mMul = m1.Mul(2.0);
	cout << "\nm1 * 2.0:\n";
	mMul.Output();
	
	// Ділення на скаляр
	cout << "\n--- Testing division ---\n";
	Matrix2D mDiv = m1;
	cout << "Before division:\n";
	mDiv.Output();
	mDiv.Div(2.0);
	cout << "After division by 2.0:\n";
	mDiv.Output();
	
	mDiv.Div(0.0);
	cout << "After attempting division by 0:\n";
	mDiv.Output();
	
	// Тестування порівнянь
	cout << "\n--- Testing comparisons ---\n";
	cout << "m1 sum = " << m1.Sum() << "\n";
	cout << "m4 sum = " << m4.Sum() << "\n";
	
	if (m1.isEqual(m4)) {
		cout << "m1 and m4 are equal\n";
	} else if (m1.isGreaterThan(m4)) {
		cout << "m1 is greater than m4\n";
	} else {
		cout << "m1 is less than m4\n";
	}
	
	// Тестування некоректних індексів
	cout << "\n--- Testing invalid index access ---\n";
	m1.setElement(5, 5, 10.0);
	m1.getElement(2, 2);
	
	cout << "\nFinal count: " << Matrix2D::getCount() << "\n";
	cout << "\n===== End of Matrix2D Class Testing =====\n";
	
	return 1;
}
