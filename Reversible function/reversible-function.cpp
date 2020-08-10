#include <vector>
#include <algorithm>

using namespace std;

class FunctionPart {
	public:
		FunctionPart(char n_op, double n_v) {
			operation = n_op;
			value = n_v;
		}

		double Apply(double s_v) const {
			if (operation == '+')
				return s_v + value;
			else if (operation == '-')
				return s_v - value;
			else if (operation == '*')
				return s_v * value;
			else if (operation == '/')
				return s_v / value;
		}

		void Invert() {
			if (operation == '+')
				operation = '-';
			else if (operation == '-')
				operation = '+';
			else if (operation == '*')
				operation = '/';
			else if (operation == '/')
				operation = '*';
		}

	private:
		char operation;
		double value;
};

class Function {
	public:
		void AddPart(char op, double value) {
			parts.push_back({op, value});
		}

		double Apply(double value) const{
			for (const FunctionPart& part : parts)
				value = part.Apply(value);
			return value;
		}

		void Invert() {
			for (FunctionPart& part : parts)
				part.Invert();
			reverse(parts.begin(), parts.end());
		}
	private:
		vector<FunctionPart> parts;
};

