/*テンプレートクラス*/
#include<iostream>

template<typename T>
class vertex{
	private:
		T x = 0;
		T y = 0;
	public:
		vertex(){std::cout << "create" << std::endl;} //デフォルトコンストラクタ
		vertex(vertex&){std::cout << "copy constract" << std::endl;} //コピーコンストラクタ
		void set(T input_x, T input_y){x = input_x; y = input_y;}
		//T get_x(){return x;}
		//T get_y(){return y;}
		T get_x();
		T get_y();
};

int main(){

	vertex<int> a1;
	vertex<double> a3;

	a1.set(1, 2);
	a3.set(1.5, 2.5);

	vertex<int> a2 = a1; //コピーコンストラクタがよばれる

	a2 = a1; //代入演算子

	std::cout << a1.get_x() << " " << a1.get_y() << std::endl;
	std::cout << a2.get_x() << " " << a2.get_y() << std::endl;
	std::cout << a3.get_x() << " " << a3.get_y() << std::endl;

	return 0;
}

//クラス外でのメンバ関数の定義
template<typename T>
T vertex<T>::get_x(){
	return x;
}

template<typename T>
T vertex<T>::get_y(){
	return y;
}
