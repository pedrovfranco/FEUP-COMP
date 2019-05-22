#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <time.h>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <list>
#include <chrono>

const double Phi = (1 + std::sqrt(5) / 2);
const double phi = (1 - std::sqrt(5) / 2);

using namespace std;


int minimum(std::vector<int> input)
{
	int min = input[0];

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] < min)
			min = input[i];
	}


	return min;
}

long long minimum(std::vector<long long> input)
{
	long long min = input[0];

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] < min)
			min = input[i];
	}


	return min;
}


int maximum(std::vector<int> input)
{
	int max = input[0];

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] > max)
			max = input[i];
	}


	return max;
}

long long maximum(std::vector<long long> input)
{
	long long max = input[0];

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] > max)
			max = input[i];
	}


	return max;
}


void swap(std::vector<int>& input, int a, int b)
{
	int temp;
	temp = input[a];

	input[a] = input[b];
	input[b] = temp;

}

void swap(std::vector<long long>& input, int a, int b)
{
	long long temp;
	temp = input[a];

	input[a] = input[b];
	input[b] = temp;

}

template <class T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


void reverse(std::vector<int>& input)
{

	for (int i = 0; i < input.size() / 2; i++)
	{
		swap(input, i, input.size() - 1 - i);
	}

}

void reverse(std::vector<long long>& input)
{

	for (int i = 0; i < input.size() / 2; i++)
	{
		swap(input, i, input.size() - 1 - i);
	}

}

template <class T>
void reverse(std::vector<T>& input)
{
	for (int i = 0; i < input.size() / 2; ++i)
	{
		swap(input[i], input[input.size() - i -1]);
	}
}


template <class T>
int sequencialSearch(const std::vector<T>& input,const T& a)
{
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == a)
			return i;
	}

	return -1;
}

int sequencialSearch(const std::string input,const char& a)
{
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == a)
			return i;
	}

	return -1;
}



long long somanprimeiros2(long long n)
{

	return ((pow(n, 2) + n) / 2);
}


long long vtoi(std::vector<int> input)
{
	long long res = 0;

	long long multi = 10;

	res += input.back();

	for (int i = input.size() - 2; i >= 0; i--) {

		res += input[i] * multi;

		multi *= 10;
	}

	return res;
}


int numlength(long long n)
{
	int length = 0;

	do {
		++length;

		n /= 10;

	} while (n);

	return length;
}

//
//long long fatorial(int n)
//{
//
//	if (n < 2)
//		return 1;
//
//	long long cont = 2;
//
//	for (int i = 3; i <= n; i++)
//	{
//		cont *= i;
//
//	}
//	return cont;
//
//}

int fatorial(int n)
{
	int res = 1;

	for (int i = 2; i <= n; i++) {
		res *= i;
	}

	return res;
}

bool if_pandigital(long long input)
{
	std::vector<int> vezes;
	std::string workstr = std::to_string(input);
	vezes.resize(10);
	int single;

	for (int i = 0; i < workstr.length(); i++) {
		single = (stoi(workstr.substr(i, 1)));

		if (vezes[single] != 0 || single > workstr.length()) {
			return false;
		}

		vezes[single]++;
	}

	if (vezes[0] != 0) {
		return false;
	}

	for (int i = 1; i <= workstr.length(); i++)

	{
		if (vezes[i] != 1) {
			return false;
		}
	}

	return true;
}




void permutations(std::vector<int>& input, std::vector<int>& temp, std::vector<std::vector<int> >& res)
{

	for (int i = 0; i < input.size(); i++) {
		//std::vector<int> temp2 = input;

		temp[temp.size() - input.size()] = input[i];

		input.erase(input.begin() + i);

		if (input.size() == 0)
			res.push_back(temp);
		else
			permutations(input, temp, res);

		input.insert(input.begin() + i, temp[temp.size() - input.size() - 1]);
	}
}

std::vector<std::vector<int> > permutations(std::vector<int> input)
{
	std::vector<int> temp(input.size(), 0);

	std::vector<std::vector<int> > resultado;

	permutations(input, temp, resultado);

	return resultado;
}


void numpermutations(std::vector<int>& input, long long temp, std::vector<long long>& res)
{

	for (int i = 0; i < input.size(); i++)
	{
		int temp2 = input[i];

		if (input.size() == 1)
		{
			res.push_back(temp * 10 + temp2);
		}
		else
		{
			input.erase(input.begin() + i);

			numpermutations(input, temp * 10 + temp2, res);

			input.insert(input.begin() + i, temp2);

		}

	}
}

std::vector<long long> numpermutations(std::vector<int> input)
{

	std::vector<long long> resultado;

	long long temp = 0;

	numpermutations(input, temp, resultado);

	return resultado;
}


void NewNumPerms(std::vector<int> &input, int curr_ite, std::vector<int> &res)
{

	if (curr_ite == input.size() - 2)
	{
		res.push_back(vtoi(input));
		swap(input, curr_ite, input.size() - 1);
		res.push_back(vtoi(input));
		swap(input, curr_ite, input.size() - 1);

	}
	else
	{
		for (int i = curr_ite; i < input.size(); i++)
		{
			swap(input, curr_ite, i);

			NewNumPerms(input, curr_ite + 1, res);

		}

		for (int i = curr_ite; i < input.size() - 1; ++i)
		{
			swap(input, i, i + 1);
		}

	}


}

std::vector<int> NewNumPerms(std::vector<int> input)
{
	std::vector<int> res;

	NewNumPerms(input, 0, res);

	return res;
}

void longNewNumPerms(std::vector<int> &input, int curr_ite, std::vector<long long> &res)
{

	if (curr_ite == input.size() - 2)
	{
		res.push_back(vtoi(input));
		swap(input, curr_ite, input.size() - 1);
		res.push_back(vtoi(input));
		swap(input, curr_ite, input.size() - 1);

	}
	else
	{
		for (int i = curr_ite; i < input.size(); i++)
		{
			swap(input, curr_ite, i);

			longNewNumPerms(input, curr_ite + 1, res);

		}

		for (int i = curr_ite; i < input.size() - 1; ++i)
		{
			swap(input, i, i + 1);
		}

	}


}

std::vector<long long> longNewNumPerms(std::vector<int> input)
{
	std::vector<long long> res;

	longNewNumPerms(input, 0, res);

	return res;
}


//Overload with string
bool if_pandigital(std::string workstr)
{
	std::vector<int> vezes;
	vezes.resize(10);
	int single;

	for (int i = 0; i < workstr.length(); i++) {
		single = (stoi(workstr.substr(i, 1)));

		if (vezes[single] != 0 || single > workstr.length()) {
			return false;
		}

		vezes[single]++;
	}

	if (vezes[0] != 0) {
		return false;
	}

	for (int i = 1; i <= workstr.length(); i++)

	{
		if (vezes[i] != 1) {
			return false;
		}
	}

	return true;
}

std::vector<int> itov(int input)
{
	std::vector<int> res;

	do {
		res.push_back(input % 10);
		input /= 10;

	} while (input);

	reverse(res);

	return res;
}


std::vector<int> itov(long long input)
{
	std::vector<int> res;

	do {
		res.push_back(input % 10);
		input /= 10;

	} while (input);

	reverse(res);

	return res;
}


void sort_vector(std::vector<int>& input)
{
	std::vector<int> copy = input;
	std::vector<int> work;

	while (copy.size() != 0) {
		int min = copy[0];
		int place = 0;

		for (int i = 0; i < copy.size(); i++) {

			if (copy[i] < min) {
				min = copy[i];
				place = i;
			}
		}
		copy.erase(copy.begin() + place);
		work.push_back(min);
	}

	input = work;
}

void sort_vector(std::vector<long long>& input)
{
	std::vector<long long> copy = input;
	std::vector<long long> work;

	while (copy.size() != 0) {
		long long min = copy[0];
		long long place = 0;

		for (long long i = 0; i < copy.size(); i++) {

			if (copy[i] < min) {
				min = copy[i];
				place = i;
			}
		}
		copy.erase(copy.begin() + place);
		work.push_back(min);
	}

	input = work;
}


std::vector<bool> to_binary(long long input)
{
	std::vector<bool> res(32, 0);

	for (int i = res.size() - 1; i >= 0; i--)
	{

		res[i] = input % 2;

		input /= 2;

	}

	return res;
}



bool vector_exists(std::vector<long long> input, long long n)
{

	if (find(input.begin(), input.end(), n) != input.end()) {
		return true;
	}
	else {
		return false;
	}
}

bool vector_exists(std::vector<double> input, double n)
{

	if (find(input.begin(), input.end(), n) != input.end()) {
		return true;
	}
	else {
		return false;
	}
}

void sort_vector(std::vector<double>& input)
{
	std::vector<double> copy = input;
	std::vector<double> work;

	while (copy.size() != 0) {
		int min = copy[0];
		int place = 0;

		for (int i = 0; i < copy.size(); i++) {

			if (copy[i] < min) {
				min = copy[i];
				place = i;
			}
		}
		copy.erase(copy.begin() + place);
		work.push_back(min);
	}

	input = work;
}

std::string bigmultiply(std::string workstr, long long n)
{
	std::vector<long long> res;
	res.resize(workstr.length() + std::to_string(n).length() + 4);
	int conta1 = 0;

	for (int i = workstr.length() - 1; i >= 0; i--) {

		int workint = stoi(workstr.substr(i, 1)) * n;
		std::string intstring = std::to_string(workint);
		int conta2 = 0;

		for (int j = intstring.length() - 1; j >= 0; j--) {

			res[res.size() - conta1 - 1 - conta2] += stoi(intstring.substr(j, 1));

			if (res[res.size() - conta1 - 1 - conta2] > 9) {
				std::string reavaluatestring = std::to_string(res[res.size() - conta1 - 1 - conta2]);
				res[res.size() - conta1 - 1 - conta2] = stoi(reavaluatestring.substr(reavaluatestring.length() - 1, 1));

				for (int l = 0; l < reavaluatestring.length() - 1; l++) {

					res[res.size() - conta1 - 1 - conta2 - l - 1] += stoi(reavaluatestring.substr(l, 1));
				}
			}
			conta2++;
		}

		conta1++;
	}

	std::string find;
	for (int i = 0; i < res.size(); i++) {
		find.append(std::to_string(res[i]));
	}

	return find.substr(find.find_first_of("123456789"));
}

std::string bigpower(std::string workstr2, int n2)
{
	std::string res = workstr2;

	for (int i = 1; i < n2; i++) {

		res = bigmultiply(res, stoi(workstr2));
	}

	return res;
}

std::string bigadd(std::string workstr3, std::string workstr4)
{

	std::vector<int> final;

	int maximo;

	if (workstr3.length() > workstr4.length())
		maximo = workstr3.length() + 3;
	else
		maximo = workstr4.length() + 3;

	final.resize(maximo);
	int j = 0;
	int i = 0;
	while (workstr3.length() < maximo || workstr4.length() < maximo) {
		i++;
		workstr3.insert(0, "0");
		workstr4.insert(0, "0");
	}

	for (int i = maximo - 1; i >= 0; i--) {

		final[i] += stoi(workstr3.substr(workstr3.length() - 1 - j, 1)) + stoi(workstr4.substr(workstr4.length() - 1 - j, 1));

		if (final[i] > 9) {
			std::string reavaluatestring = std::to_string(final[i]);
			final[i] = stoi(reavaluatestring.substr(reavaluatestring.length() - 1, 1));

			for (int l = 0; l < reavaluatestring.length() - 1; l++) {

				final[i - l - 1] += stoi(reavaluatestring.substr(l, 1));
			}
		}
		j++;
	}

	std::string find;
	for (int i = 0; i < final.size(); i++) {
		find.append(std::to_string(final[i]));
	}

	return find.substr(find.find_first_of("123456789"));
}


std::vector<int> bigadd2(std::vector<int> input1, std::vector<int> input2)
{

	std::vector<int> res;

	int max;

	if (input1.size() > input2.size())
		max = input1.size();
	else
		max = input2.size();

	res.resize(max + 1);

	int temp = 0;

	int seguinte = 0;

	bool end;

	for (int i = 0; i <= max; i++)
	{
		end = 1;

		if (i >= input1.size())
		{
			end = 0;

			if (i < input2.size())
				temp += input2[input2.size() - 1 - i];

		}

		if (i >= input2.size())
		{
			end = 0;

			if (i < input1.size())
				temp += input1[input1.size() - 1 - i];

		}

		if (end)
			temp += input1[input1.size() - 1 - i] + input2[input2.size() - 1 - i];

		res[res.size() - 1 - i] = temp % 10;

		temp /= 10;

	}

	if (res.front() == 0)
		res.erase(res.begin());

	return res;
}

std::vector<int> bigmultiply2(std::vector<int> input1, std::vector<int> input2)
{
	std::vector<int> res;

	int push_value = 0;

	std::vector<std::vector<int>> tempsums;

	std::vector<int> row;

	for (int i = input2.size() - 1; i >= 0; i--)
	{
		row = { 0 };

		for (int j = 0; j < input2[i]; j++)
		{
			row = bigadd2(row, input1);
		}


		for (int j = 0; j < push_value; j++)
		{
			row.push_back(0);
		}

		push_value++;

		res = bigadd2(res, row);
	}

	return res;
}

std::vector<int> bigpower2(std::vector<int> input, int n)
{

	std::vector<int> res = input;

	for (int i = 1; i < n; i++) {

		res = bigmultiply2(res, input);
	}

	return res;

}



//std::vector<int> bigmultiply2(std::vector<int> input1, std::vector<int> input2)
//{
//
//
//
//
//}



std::string bigfibonacci(long long index)
{

	std::vector<std::string> res = { 2, std::to_string(1) };

	long long i;

	for (i = 2; i < index; i++) {

		res.push_back(bigadd(res[i - 1], res[i - 2]));
	}

	return res[i - 1];
}

std::string bigfatorial(int n)
{
	if (n < 2)
		return "1";

	std::string res = "2";

	for (int i = 3; i <= n; i++) {
		res = bigmultiply(res, i);
	}

	return res;
}

double combinacoes(int n, int p)
{

	double count = 1;

	if (p > (n / 2)) {
		return combinacoes(n, n - p);
	}
	else {
		for (int i = n; i >= (n - p) + 1; i--) {
			count *= i;
		}

		return round(count / fatorial(p));
	}
}


int sum_digits(std::vector<int> input)
{
	int sum = 0;

	for (int i = 0; i < input.size(); i++)
		sum += input[i];

	return sum;
}

int sum_digits(int n)
{
	int sum = 0;
	int temp = n;

	while (temp)
	{
		sum += temp % 10;
		temp /= 10;
	}

	return sum;
}


double combinacoes2(int n, int p)
{
	double fatorial = 1;
	double count = 1;

	if (p > (n / 2)) {
		return combinacoes(n, n - p);
	}
	else {
		for (int i = n; i >= (n - p) + 1; i--) {
			count *= i;
		}
		for (int j = 1; j <= p; j++) {
			fatorial *= j;
		}
		return round(count / fatorial);
	}
}

long long somanprimeiros1(long long n)
{
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		res += i;
	}

	return res;
}

long long fibonacci1(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fibonacci1(n - 1) + fibonacci1(n - 2);
}

long long fibonacci3(int n)
{

	std::vector<long long> res = { 1, 1 };

	long long i;

	for (i = 2; i < n; i++) {

		res.push_back(res[i - 1] + res[i - 2]);
	}

	return res[i - 1];
}

bool if_primo(long long n)
{
	int i = 0;

	if (n <= 1)
		return false;

	if (n == 2 || n == 3)
		return true;

	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}

	return true;
}

bool is_prime(int n)
{
	if (n <= 1)
		return false;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}

	return true;
}

bool if_palindrome(long long n)
{
	/*if (n < 10)
	{
	return false;
	}*/

	std::string workstr = std::to_string(n);
	std::string workstr2 = workstr;

	reverse(workstr2.begin(), workstr2.end());

	if (workstr == workstr2)
		return true;
	else
		return false;
}

//Overload for strings
bool if_palindrome(std::string workstr)
{

	std::string workstr2 = workstr;

	reverse(workstr2.begin(), workstr2.end());

	if (workstr == workstr2)
		return true;
	else
		return false;
}

std::vector<long long> divisores(long long n)
{
	int a, i;
	std::vector<long long> res;

	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			res.push_back(i);
	}
	a = res.size() - 1;

	for (i = a; i >= 0; i--) {
		if (res[i] == n / res[i]) {
			continue;
		}

		res.push_back(n / res[i]);
	}

	return res;
}


long long somadedivisores(long long n)
{
	int a, i;
	std::vector<long long> res = divisores(n);
	long long sum = 0;

	for (unsigned int i = 0; i < res.size(); i++) {
		sum += res[i];
	}

	return sum + 1;
}

long long ultdivprimo(long long n)
{
	int a = 0, i;
	long long res[100];

	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) // A divisÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o entre "n" e o seu divisor mais pequeno resulta no seu maior divisor
		{ // Assim, consigo obter os divisores de "n" por ordem decrescente
	a++;
	res[a] = i;
	if (if_primo(n / i) == true)
		return n / i;
}
}

for (i = a; i > 0; i--) {
	if (if_primo(res[i]) == true)
		return res[i];
}

return 0;
}

int numerodecadeias(long long n)
{
	long long res = n;
	int i = 0;
	do {
		i++;

		if (res % 2 == 0)
			res /= 2;
		else
			res = 3 * res + 1;

	} while (res != 1);
	i++;
	return i;
}

bool if_triangular(double n)
{
	double sum = sqrt(2 * (n + 0.125)) - (0.5);

	return (sum == (int)sum);
}

bool if_hexagonal(double n)
{
	double sum = sqrt((n + 0.125) / 2) + (0.25);

	return (sum == (int)sum);
}

std::string problem38(long long input)
{

	std::string res;
	std::string final;

	for (int i = 1; res.length() < 10; i++) {
		res.append(std::to_string(input * i));
		if (res.length() == 9) {
			if (if_pandigital(res)) {
				final.append(std::to_string(input));
				final.append(" : ");
				final.append(res);
				return final;
			}
		}
	}

	return "";
}

int numerodesolucoesproblem39(long long perimeter)
{
	int conta = 0;

	for (int i = 2; i < perimeter / 2; i++) {
		for (int j = 2; j < perimeter / 2; j++) {
			if (sqrt(pow(i, 2) + pow(j, 2)) + j + i == perimeter)
				conta++;
		}
	}

	return conta / 2;
}

std::vector<int> primelist(int n)
{
	std::vector<int> res;

	for (int i = 2; res.size() < n; i++) {
		if (if_primo(i)) {
			res.push_back(i);
		}
	}

	return res;
}


long long problem28(int n)
{
	long long sum = 0;

	for (int i = 3; i <= n; i += 2) {

		sum += 4 * pow(i, 2) - 6 * i + 6;
	}

	return sum + 1;
}

double problem282(int n)
{

	return (((4 * pow(n, 3)) + (3 * pow(n, 2)) + 8 * n - 9) / 6);
}

//void vector_sort_repeat(std::vector<long long>& input)
//{
//	long long temp;
//
//	sort_vector(input);
//
//	for (int i = 1; i < input.size(); i++)
//	{
//
//		if (input[i - 1] == input[i])
//		{
//			input.erase(input.begin() + i);
//		}
//	}
//
//}

int namescore(std::string input)
{
	int sum = 0;
	int coisas;

	for (int i = 0; i < input.length(); i++) {

		coisas = (char)(input[i]);
		coisas -= 64;
		sum += coisas;
	}

	return sum;
}

long long numeropentagonal(int n)
{

	return (n * (3 * n - 1) / 2);
}

double problem58(int n)
{

	long long res;
	double countprimo = 0;
	double countall = 2 * (n - 1) + 1;

	for (int i = 3; i <= n; i += 2) {

		// a = 1

		res = i * i - 1 * (i - 1);
		if (if_primo(res))
			countprimo++;

		// a = 2

		res = i * i - 2 * (i - 1);
		if (if_primo(res))
			countprimo++;

		// a = 3

		res = i * i - 3 * (i - 1);
		if (if_primo(res))
			countprimo++;
	}

	return (countprimo / countall);
}


bool problem47(int n)
{
	std::vector<long long> div = divisores(n);

	if (div.size() % 2) {
		div.erase(div.begin() + (div.size() - 1) / 2);
	}

	for (int i = 0; i < (div.size() / 2); i++) {
		if (if_primo(div[i]) && if_primo(div[div.size() - i - 1])) {
			return true;
		}
	}

	return false;
}


// std::vector<long long> SieveOfEratosthenes(long long n)
// {

// 	std::vector<bool> primes;

// 	primes.resize(n + 1);

// 	for (int i = 0; i < primes.size(); i++) // Fill vector with true
// 	{
// 		primes[i] = true;
// 	}

// 	for (int i = 2; i <= sqrt(n); i++) {
// 		if (i == 5) {
// 			int a = 0;
// 		}
// 		if (primes[i]) {

// 			for (int j = 0; i * i + j * i <= n; j++) {
// 				primes[i * i + j * i] = false;
// 			}
// 		}
// 	}

// 	std::vector<long long> res;

// 	for (int i = 2; i < primes.size(); i++) {
// 		if (primes[i]) {
// 			res.push_back(i);
// 		}
// 	}

// 	return res;
// }

std::vector<int> SieveOfEratosthenes(int n)
{

	std::vector<bool> primes;

	primes.resize(n + 1);

	for (int i = 0; i < primes.size(); i++) // Fill vector with true
	{
		primes[i] = true;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		if (i == 5) {
			int a = 0;
		}
		if (primes[i]) {

			for (int j = 0; i * i + j * i <= n; j++) {
				primes[i * i + j * i] = false;
			}
		}
	}

	std::vector<int> res;

	for (int i = 2; i < primes.size(); i++) {
		if (primes[i]) {
			res.push_back(i);
		}
	}

	return res;
}


bool problem55(long long n)
{

	int i = 0;

	std::string curr = std::to_string(n);
	std::string final;

	while (i < 50) {
		i++;

		std::string workstr2 = curr;
		reverse(workstr2.begin(), workstr2.end());

		curr = bigadd(curr, workstr2);

		if (if_palindrome(curr)) {
			return true;
		}
	}

	return false;
}


bool problem55_2(long long n)
{

	int i = 0;

	long long curr = n;

	while (i < 50) {
		i++;

		std::string workstr2 = std::to_string(curr);
		reverse(workstr2.begin(), workstr2.end());

		curr += stoll(workstr2);

		if (if_palindrome(curr)) {
			return true;
		}
	}

	return false;
}

//Returns a vector with the numerator in index 0 and the denominator in index 1
std::vector<long long> divisaointeira(double input)
{
	std::vector<long long> res{ 0,0 };

	double temp = input;

	long long i = 1;

	while (!(int)temp)
	{
		i++;
		temp = i * input;
	}

	res[0] = temp;
	res[1] = i;

	return res;
}

double problem57(int n)
{

	if (n == 1)
		return 1.5;

	double res = 2 + (double)1 / 2;

	for (int i = 2; i < n; i++) {

		res = 1 / res;
		res += 2;
	}

	return (1 / res) + 1;
}

std::vector<long long> problem57_2(int n)
{

	std::vector<long long> res = { 3, 2 };

	if (n == 1)
		return res;

	res = { 5, 2 };

	for (int i = 2; i < n; i++) {

		// Switching values
		res.push_back(res[1]);
		res.push_back(res[0]);
		res.erase(res.begin());
		res.erase(res.begin());

		res[0] += res[1] * 2;
	}

	// Switching values
	res.push_back(res[1]);
	res.push_back(res[0]);
	res.erase(res.begin());
	res.erase(res.begin());

	res[0] += res[1];

	return res;
}

std::vector<std::string> problem57_3(int n)
{

	std::vector<std::string> res = { std::to_string(3), std::to_string(2) };

	if (n == 1)
		return res;

	res = { std::to_string(5), std::to_string(2) };

	for (int i = 2; i < n; i++) {

		// Switching values
		res.push_back(res[1]);
		res.push_back(res[0]);
		res.erase(res.begin());
		res.erase(res.begin());

		res[0] = bigadd(res[0], bigmultiply(res[1], 2));
	}

	// Switching values
	res.push_back(res[1]);
	res.push_back(res[0]);
	res.erase(res.begin());
	res.erase(res.begin());

	res[0] = bigadd(res[0], res[1]);

	return res;
}

std::vector<std::string> problem65(int n)
{

	std::vector<std::string> res;

	std::vector<int> add = { 2 };

	int j = 0;

	for (int i = 0; add.size() < n; i++) {

		if (i % 3 == 1) {
			j++;
			add.push_back(j * 2);
		}
		else
			add.push_back(1);
	}

	res = { std::to_string(1), std::to_string(add.back()) };

	for (int i = 2; i < n; i++) {

		res[0] = bigadd(bigmultiply(res[1], add[add.size() - i]), res[0]);

		// Switching values
		std::iter_swap(res.begin(), res.begin() + 1);
	}

	res[0] = bigadd(bigmultiply(res[1], add[0]), res[0]);

	return res;
}

//std::vector<long long> primelista = SieveOfEratosthenes(20000);
//
//bool problem60(std::vector<long long> primes)
//{
//
//	std::string workstr;
//
//	long long temp;
//
//	for (int i = 0; i < primes.size(); i++)
//	{
//
//		for (int j = i + 1; j < primes.size(); j++)
//		{
//
//			workstr = std::to_string(primes[i]);
//			workstr += std::to_string(primes[j]);
//
//			temp = stoll(workstr);
//
//			if (!std::binary_search(primelista.begin(), primelista.end(), temp))
//				return false;
//
//			workstr = std::to_string(primes[j]);
//			workstr += std::to_string(primes[i]);
//
//			temp = stoll(workstr);
//
//			if (!std::binary_search(primelista.begin(), primelista.end(), temp))
//				return false;
//
//		}
//
//	}
//
//
//	return true;
//
//}

bool problem60_2(std::vector<long long> primes)
{

	long long temp1;

	long long temp2;

	long long res;

	for (int i = 0; i < primes.size(); i++) {
		temp1 = primes[i];

		if (temp1 == 0)
			continue;

		for (int j = i + 1; j < primes.size(); j++) {
			temp2 = primes[j];

			res = temp1 * pow(10, numlength(temp2));
			res += temp2;

			if (!if_primo(res))
				return false;

			res = temp2 * pow(10, numlength(temp1));
			res += temp1;

			if (!if_primo(res))
				return false;
		}
	}

	return true;
}

bool problem60_2(std::vector<int> primes)
{

	int temp1;

	int temp2;

	long long res;

	for (int i = 0; i < primes.size(); i++) {
		temp1 = primes[i];

		for (int j = i + 1; j < primes.size(); j++) {
			temp2 = primes[j];

			res = temp1 * pow(10, numlength(temp2));
			res += temp2;

			if (!if_primo(res))
				return false;

			res = temp2 * pow(10, numlength(temp1));
			res += temp1;

			if (!if_primo(res))
				return false;
		}
	}

	return true;
}

int ipow(int base, int exp)
{
	int result = 1;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}

	return result;
}

bool problem60_3(std::vector<int> input, int target, std::vector<int>& primes)
{
	int temp1;

	long long res;

	for (int i = 0; i < input.size(); i++)
	{
		temp1 = input[i];

		res = temp1 * ipow(10, numlength(target));
		res += target;

		if (!std::binary_search(primes.begin(), primes.end(), res))
			return false;

		res = target * ipow(10, numlength(temp1));
		res += temp1;

		if (!std::binary_search(primes.begin(), primes.end(), res))
			return false;
	}

	return true;
}


std::vector<int> problem35(int n)
{
	std::vector<int> work = itov(n);

	int temp1 = work[0];
	int temp2;

	std::vector<int> res;
	res.push_back(n);

	for (int i = 0; i < work.size() - 1; ++i)
	{

		for (int i = 1; i < work.size(); ++i)
		{
			temp2 = work[i];
			work[i] = temp1;
			temp1 = temp2;
		}
		work[0] = temp1;

		res.push_back(vtoi(work));
	}

	return res;
}


bool is_square(long long n)
{

	return ((long long)sqrt(n) == sqrt(n));
}


long long mdc(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		return mdc(b, a % b);
}



long long highest_common_divisor_2(long long n, long long m)
{

	for (int i = n; i > 0; i--) {

		if (n % i == 0 && m % i == 0) {
			return i;
		}
	}
}

int num_chains(long long n)
{

	std::string currnum = std::to_string(n);

	std::string count;

	std::vector<std::string> chain = { std::to_string(n) };

	while (1) {

		for (int i = 0; i < currnum.length(); i++)
			count = bigadd(count, bigfatorial(stoi(currnum.substr(i, 1))));

		sort(chain.begin(), chain.end());

		if (std::binary_search(chain.begin(), chain.end(), count)) {
			return chain.size();
		}
		else
			chain.push_back(count);

		currnum = count;
		count = "0";
	}

	return chain.size();
}

int num_chains_2(long long n)
{

	long long currnum = n;

	long long count = 0;

	std::string workstr;

	std::vector<long long> chain = { n };

	while (1) {
		workstr = std::to_string(currnum);

		for (int i = 0; i < workstr.length(); i++)
			count += fatorial(stoll(workstr.substr(i, 1)));

		sort(chain.begin(), chain.end());

		if (std::binary_search(chain.begin(), chain.end(), count)) {
			return chain.size();
		}
		else
			chain.push_back(count);

		currnum = count;
		count = 0;
	}

	return chain.size();
}

bool is_permutation(std::vector<long long> input)
{

	std::vector<int> row1(10, 0);
	std::vector<int> row2(10, 0);

	long long temp;

	temp = input[0];

	while (temp)
	{
		row1[temp % 10]++;

		temp /= 10;
	}

	for (int i = 1; i < input.size(); i++) // O vetor vezes contem o numero de vezes que cada digito aparece em temp no indice desse digito, por exemplo: "11232" : vezes[1] == 2 , vezes[2] == 2, vezes[3] == 1 tudo o resto ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â© 0
	{
		temp = input[i];

		while (temp)
		{
			row2[temp % 10]++;

			temp /= 10;
		}

		if (row1 != row2)
			return false;

		for (int i = 0; i < row2.size(); i++)
			row2[i] = 0;
	}

	return true;
}

bool is_permutation2(std::vector<long long> input)
{

	std::vector<std::vector<int> > vezes;

	std::vector<int> row(10, 0);

	long long temp;

	temp = input[0];

	while (temp)
	{
		row[temp % 10]++;

		temp /= 10;
	}

	vezes.push_back(row);


	for (int i = 1; i < input.size(); i++) // O vetor vezes contem o numero de vezes que cada digito aparece em temp no indice desse digito, por exemplo: "11232" : vezes[1] == 2 , vezes[2] == 2, vezes[3] == 1 tudo o resto ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â© 0
	{
		for (int j = 0; j < row.size(); j++)
		{
			row[j] = 0;
		}

		temp = input[i];

		while (temp)
		{
			row[temp % 10]++;

			temp /= 10;
		}

		vezes.push_back(row);

		if (vezes[i - 1] != vezes[i])
			return false;

	}

	return true;
}


int euler_totient(int d)
{
	std::vector<long long> divd = divisores(d);

	int count = 0;


	for (int n = 2; n < d; n++) {

		for (int j = 0; j < divd.size(); j++) //Verificar se ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â© divisivel por qualquer um dos divisores de d de modo a averiguar se forma uma fraÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o reduzida
		{

			if (n % divd[j] == 0) // Se for divisivel por qualquer um dos divisores de d, entÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o seguir para o numerador seguinte.
				goto next_n;
		}

		count++;

		next_n:;
	}

	return count + 1;
}

int next(int n)
{
	int result = 0;
	while (n)
		result += (n % 10) * (n % 10), n /= 10;
	return result;
}

std::vector<int> problem64(int n)
{
	std::vector<int> res;

	int m = 0;

	int d = 1;

	int a = sqrt(n);

	int a0 = a;

	int i = 0;

	bool flag;

	while (i != 1000) {
		i++;

		m = d * a - m;

		d = (n - m * m) / d;

		a = ((double)(a0 + m) / d);

		res.push_back(a);
	}

	for (int i = 1; i < res.size(); i++) {

		if (res[i] == res[0]) {
			flag = false;

			for (int l = 1; l < floor((double)res.size() / i); l++) {

				for (int j = 0; j < i; j++) {
					if (res[j] != res[l * i + j]) {
						flag = true;
						break;
					}
				}

				if (flag)
					break;
			}

			if (flag)
				continue;
			else {
				std::vector<int> temp(res.begin(), res.begin() + i);

				return temp;
			}
		}
	}
}


void vector_cout(std::vector<int> input)
{
	for (int i = 0; i < input.size(); i++)
	{
		std::cout << input[i];
	}

}


void vector_sort2(std::vector<int>& input)
{
	int min;

	int place;

	int j = 0;

	while (j < input.size())
	{

		min = input[j];
		place = j;

		for (int i = j + 1; i < input.size(); i++)
		{
			if (input[i] < min)
			{
				place = i;
				min = input[i];
			}
		}

		swap(input, place, j);

		j++;
	}

}

void vector_sort2(std::vector<long long>& input)
{

	long long min;

	int place;

	int j = 0;

	while (j < input.size())
	{

		min = input[j];
		place = j;

		for (int i = j + 1; i < input.size(); i++)
		{
			if (input[i] < min)
			{
				place = i;
				min = input[i];
			}
		}

		swap(input, place, j);

		j++;
	}

}


std::vector<int> problem47(int n, std::vector<int> &primes)
{
	std::vector<int> res;

	int count = 0;

	int curr = n;

	for (int i = 0; i < primes.size(); i++)
	{
		if (curr == 1)
			break;

		count = 0;

		while (!(curr % primes[i]))
		{
			count++;
			curr /= primes[i];
		}

		if (count != 0)
			res.push_back(count * primes[i]);
	}

	return res;
}


void removeDuplicates(std::vector<int> &v)
{

	int i = 0;

	int temp;

	while (i < v.size())
	{

		temp = v[i];

		for (int j = 0; j < v.size(); j++)
		{

			if (i != j && temp == v[j])
			{
				v.erase(v.begin() + j);
				j--;
			}

		}

		i++;
	}

}


std::vector<int> union_new(std::vector<int> v1, std::vector<int> v2)
{
	std::vector<int> res;

	for (int i = 0; i < v1.size(); i++)
	{

		if (std::binary_search(v2.begin(), v2.end(), v1[i]))
			res.push_back(v1[i]);

	}


	return res;
}


int binary_search(std::vector<int> &v, int n)
{

	if (n > v.back() || n < v.front())
		return -1;

	int middle = v.size() / 2;

	while (!(v[middle + 1] > n && v[middle] < n))
	{

		if (v[middle] == n)
			return middle;

		if (n < v[middle])
			middle /= 2;
		else
			middle = (v.size() - middle) / 2;
	}

	return -1;
}

void problem61_work(const std::vector<std::vector<int>>& P, std::vector<bool> flags, int inicial, int temp, int sum)
{

	if (flags[0])
	{
		for (int j = 0; j < P[0].size(); j++)
		{

			if (temp % 100 == P[0][j] / 100)
			{
				flags[0] = false;
				problem61_work(P, flags, inicial, P[0][j], sum + P[0][j]);
				flags[0] = true;
			}

		}
	}

	if (flags[1])
	{
		for (int j = 0; j < P[1].size(); j++)
		{

			if (temp % 100 == P[1][j] / 100)
			{
				flags[1] = false;
				problem61_work(P, flags, inicial, P[1][j], sum + P[1][j]);
				flags[1] = true;
			}

		}
	}

	if (flags[2])
	{
		for (int j = 0; j < P[2].size(); j++)
		{

			if (temp % 100 == P[2][j] / 100)
			{
				flags[2] = false;
				problem61_work(P, flags, inicial, P[2][j], sum + P[2][j]);
				flags[2] = true;
			}

		}
	}

	if (flags[3])
	{
		for (int j = 0; j < P[3].size(); j++)
		{

			if (temp % 100 == P[3][j] / 100)
			{
				flags[3] = false;
				problem61_work(P, flags, inicial, P[3][j], sum + P[3][j]);
				flags[3] = true;
			}

		}
	}

	if (flags[4])
	{
		for (int j = 0; j < P[4].size(); j++)
		{

			if (temp % 100 == P[4][j] / 100)
			{
				flags[4] = false;
				problem61_work(P, flags, inicial, P[4][j], sum + P[4][j]);
				flags[4] = true;
			}

		}
	}

	bool flagtemp = true;

	for (int i = 0; i < flags.size(); i++)
	{
		if (flags[i])
		{
			flagtemp = false;
			break;
		}
	}

	if (flagtemp && temp % 100 == inicial / 100)
	{
		std::cout << sum << "\n";
	}


}


int problem61()
{
	std::vector<std::vector<int>> P;
	P.resize(6);

	int tempadd, tempcount;

	// Gerar os nÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Âºmeros de P
	tempadd = 0;
	tempcount = 1;
	while (tempadd < 10000)
	{
		if (tempadd > 999)
			P[0].push_back(tempadd);
		tempadd += tempcount;
		tempcount += 1;
	}

	tempadd = 0;
	tempcount = 1;
	while (tempadd < 10000)
	{
		if (tempadd > 999)
			P[1].push_back(tempadd);
		tempadd += tempcount;
		tempcount += 2;
	}

	tempadd = 0;
	tempcount = 1;
	while (tempadd < 10000)
	{
		if (tempadd > 999)
			P[2].push_back(tempadd);
		tempadd += tempcount;
		tempcount += 3;
	}

	tempadd = 0;
	tempcount = 1;
	while (tempadd < 10000)
	{
		if (tempadd > 999)
			P[3].push_back(tempadd);
		tempadd += tempcount;
		tempcount += 4;
	}

	tempadd = 0;
	tempcount = 1;
	while (tempadd < 10000)
	{
		if (tempadd > 999)
			P[4].push_back(tempadd);
		tempadd += tempcount;
		tempcount += 5;
	}

	tempadd = 0;
	tempcount = 1;
	while (tempadd < 10000)
	{
		if (tempadd > 999)
			P[5].push_back(tempadd);
		tempadd += tempcount;
		tempcount += 6;
	}


	std::vector<bool> flags(5, true);


	for (int i = 0; i < P[5].size(); i++)
	{
		problem61_work(P, flags, P[5][i], P[5][i], P[5][i]);
	}

	return 0;
}


int problem85(const int &w,const int &h)
{
	return (w*w + w)*(h*h + h)/4;
}



void problem18(std::vector<std::vector<int>> &input, unsigned int iteration, unsigned int pos, unsigned int temp, unsigned int &max, unsigned int &sum)
{
	if (iteration == input.size() - 1)
	{
		temp += input[iteration][pos];
		sum++;

		// if (temp == 1074)
		// 	int a = 1;

		if (temp > max)
		{
			max = temp;
		}
		
	}
	else
	{
		problem18(input, iteration + 1, pos, temp + input[iteration][pos], max, sum);
		problem18(input, iteration + 1, pos + 1, temp + input[iteration][pos], max, sum);
	}

}

int problem18(std::vector<std::vector<int>> &input)
{

	unsigned int max = 0;
	unsigned int sum = 0;
	problem18(input, 0, 0, 0, max, sum);
	return max;
}

int singleromantoint(char input)
{

	//std::string work = {{'I', 'V', 'X', 'L', 'C', 'D', 'M'}, {1, 5, 10, 50, 100, 500, 1000}};

	if (input == 'I')
		return 1;
	if (input == 'V')
		return 5;
	if (input == 'X')
		return 10;
	if (input == 'L')
		return 50;
	if (input == 'C')
		return 100;
	if (input == 'D')
		return 500;
	if (input == 'M')
		return 1000;

	return -1;
}

int Romantoint(std::string input)
{
	std::string work = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

	if (input.size() == 0)
		return 0;
	
	int count = 0;

	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == 'I' && (input[i+1] == 'V' || input[i+1] == 'X') || input[i] == 'X' && (input[i+1] == 'L' || input[i+1] == 'C') || input[i] == 'C' && (input[i+1] == 'D' || input[i+1] == 'M'))
		{
			count += singleromantoint(input[i+1]) - singleromantoint(input[i]);
			i++;
		}
		else
		{
			count += singleromantoint(input[i]);

		}
	}


	return count;
}

std::string singlenumbertoroman(int input)
{

	if (input == 900)
		return "CM";
	else if (input == 400)
		return "CD";
	else if (input == 90)
		return "XC";
	else if (input == 40)
		return "XL";
	else if (input == 9)
		return "IX";
	else if (input == 4)
		return "IV";

	std::string res;

	while (input)
	{

		if (input >= 1000)
		{
			res+= "M";
			input -= 1000;
		}
		else if (input >= 500)
		{
			res+= "D";
			input -= 500;
		}
		else if (input >= 100)
		{
			res+= "C";
			input -= 100;
		}
		else if (input >= 50)
		{
			res+= "L";
			input -= 50;
		}
		else if (input >= 10)
		{
			res+= "X";
			input -= 10;
		}
		else if (input >= 5)
		{
			res+= "V";
			input -= 5;
		}
		else if (input >= 1)
		{
			res+= "I";
			input -= 1;
		}

	}

	return res;
}


std::string inttoroman(int input)
{
	int size =numlength(input);
	int sizepow = pow(10,size);
	int curr;
	std::string res;

	while(size)
	{

		curr = input % (int)pow(10,size);
		curr -= curr % (int)pow(10,size- 1);

		res += singlenumbertoroman(curr);

		size--;
	}

	return res;
}





int main()
{
	std::cout.precision(6);
	auto begin = std::chrono::high_resolution_clock::now();

	int maxRuns = 10;
	for (int executionCounter = 0; executionCounter < maxRuns; executionCounter++)
	{
	

	//-----------------------------------PROBLEM 1----------------------------------------

	/*int sum = 0;

	for (int i = 1; i < 1001; i++)
	{

	if (i % 3 == 0 || i % 5 == 0)
	sum += i;

	}
	cout << "O valor e: " << sum;

	return 0;*/

	//-----------------------------------PROBLEM 2----------------------------------------

	/*	long sum = 0;

	for (int i = 2; i <34; i++)
	{



	if (fibonacci1(i) % 2 == 0)
	sum += fibonacci1(i);


	}


	cout << "O valor e: " << sum;*/

	//-----------------------------------PROBLEM 3----------------------------------------

	//cout << ultdivprimo(600851475143);

	//-----------------------------------PROBLEM 4----------------------------------------

	//int max = 0;

	// for (int i = 999; i > 100; i--)
	// {
	// 	for (int j = i; j > 800; j--)
	// 	{

	// 		if (if_palindrome(i*j))
	// 		{
	// 			if (i*j > max)
	// 				max = i*j;
	// 		}

	// 	}

	// }

	//fim:
	//cout << max;

	//-----------------------------------PROBLEM 5----------------------------------------

	//for (int i = 1 ; ; i++)
	//{

	//	if (i % 2 == 0 && i % 3 == 0 && i % 4 == 0 && i % 5 == 0 && i % 6 == 0 && i % 7 == 0 && i % 8 == 0 && i % 9 == 0 && i % 10 == 0 && i % 11 == 0 && i % 12 == 0 && i % 13 == 0 && i % 14 == 0 && i % 15 == 0 && i % 16 == 0 && i % 17 == 0 && i % 18 == 0 && i % 19 == 0 && i % 20 == 0)
	//	{
	//		cout << i;
	//		break;
	//	}
	//}
	//

	//-----------------------------------PROBLEM 6----------------------------------------

	//long long sum1 = 0, sum2 = 0;

	//for (int i = 1; i <= 100; i++)
	//{
	//	sum1 += pow(i, 2);

	//	sum2 += i;

	//}
	//sum2 = pow(sum2, 2);

	//cout << "O resultado e: " << sum2 - sum1;

	//-----------------------------------PROBLEM 7----------------------------------------

	// int j = 0;

	// for (int i = 1; ; i++)
	// {
	// 	if (if_primo(i))
	// 	{
	// 		j++;
	// 	}

	// 	if (j == 10001)
	// 	{
	// 		cout << i;
	// 		break;
	// 	}
	// }

	//-----------------------------------PROBLEM 8----------------------------------------

	// string input = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

	// long long cont = 1,max =0;

	// for ( int i = 0; i < input.length()-13 ; i++)
	// {
	// 	for (int j = i; j < i + 13 ; j++)
	// 	{
	// 		cont *= stoi(input.substr(j,1));
	// 	}

	// 	if (cont > max)	max = cont;

	// 	cont = 1;
	// }

	// cout << max;

	//-----------------------------------PROBLEM 9----------------------------------------

	// bool leave = false;
	// for (int i = 100; i<500 ; i++)
	// {
	// 	for (int j = 100 ; j<500 ; j++)
	// 	{
	// 		double c = sqrt(i*i + j*j);
	// 		if (i + j + c == 1000)
	// 		{
	// 			cout << i*j*c;
	// 			leave = true;
	// 			break;
	// 		}
	// 	}

	// 	if (leave)
	// 		break;
	// }

	//-----------------------------------PROBLEM 10----------------------------------------

	// long long sum=0;

	// for (int i = 2; i <= 2000000; i++)
	// {
	// 	if (if_primo(i))
	// 	sum += i;
	// }

	// cout << sum;

	//-----------------------------------PROBLEM 11----------------------------------------

	//std::ifstream file;
	//file.open("11.txt");

	//std::string workstr;

	//int res[20][20];

	//for (int i = 0; i < 20; i++) //Registar os nÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Âºmero da grid no array res
	//{

	//	for (int j = 0; j < 20; j++)
	//	{
	//		file >> workstr;

	//		res[i][j] = stoi(workstr);

	//	}

	//}

	//long long multi;
	//long long max = 0;

	////MultiplicaÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o dos nÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Âºmeros na diagonal, esquerda para a direita

	//for (int i = 0; i < 17; i++) //IteraÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o do numero inicial na vertical
	//{

	//	for (int j = 0; j < 17; j++) //IteraÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o do numero inicial na horizontal
	//	{

	//		multi = res[i][j] * res[i + 1][j + 1] * res[i + 2][j + 2] * res[i + 3][j + 3];

	//		if (multi > max)
	//			max = multi;

	//	}

	//}

	////MultiplicaÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o dos nÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Âºmeros na diagonal, direita para a esquerda

	//for (int i = 0; i < 17; i++) //IteraÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o do numero inicial na vertical
	//{

	//	for (int j = 19; j > 2; j--) //IteraÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o do numero inicial na horizontal
	//	{

	//		multi = res[i][j] * res[i + 1][j - 1] * res[i + 2][j - 2] * res[i + 3][j - 3];

	//		if (multi > max)
	//			max = multi;

	//	}

	//}

	////MultiplicaÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o dos nÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Âºmeros na horizontal

	//for (int i = 0; i < 20; i++) //IteraÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o do numero inicial na vertical
	//{

	//	for (int j = 0; j < 17; j++) //IteraÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o do numero inicial na horizontal
	//	{

	//		multi = res[i][j] * res[i][j + 1] * res[i][j + 2] * res[i][j + 3];

	//		if (multi > max)
	//			max = multi;

	//	}

	//}

	////MultiplicaÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o dos nÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Âºmeros na vertical

	//for (int i = 0; i < 17; i++) //IteraÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o do numero inicial na vertical
	//{

	//	for (int j = 0; j < 20; j++) //IteraÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o do numero inicial na horizontal
	//	{

	//		multi = res[i][j] * res[i + 1][j] * res[i + 2][j] * res[i + 3][j];

	//		if (multi > max)
	//			max = multi;

	//	}

	//}

	//std::cout << max;

	//-----------------------------------PROBLEM 12----------------------------------------

	// for (int i = 1; ; i++)
	// {
	// 	int temp = somanprimeiros2(i);
	// 	if (divisores(temp).size() > 500)
	// 	{
	// 		cout << temp;
	// 		break;
	// 	}
	// }

	//-----------------------------------PROBLEM 13----------------------------------------

	//
	//ifstream file("c:/problem13.txt");
	//
	//string digit;
	//
	//
	//double ola=0;
	//
	//
	//int i = 0;
	//while (file >> digit)
	//{
	//	ola += stod(digit);
	//	i++;
	//}
	//cout.precision(17);
	//
	//cout << ola;

	//string conta = "0";
	//
	//while (file >> digit)
	//{
	//	bigadd(conta, digit);
	//
	//}
	//
	//cout << digit;

	//-----------------------------------PROBLEM 14----------------------------------------

	//int max = 0;
	//int num;
	//for (int i = 1; i <= 1000000; i++)
	//{
	//	if (numerodecadeias(i) > max)
	//	{
	//		max = numerodecadeias(i);
	//		num = i;
	//	}
	//}
	//
	//cout << num << " " << max ;

	//-----------------------------------PROBLEM 15----------------------------------------

	//cout << combinacoes2(40, 20);

	//-----------------------------------PROBLEM 16----------------------------------------

	// string res = bigpower(to_string(2), 1000);
	// int conta = 0;

	// for (int i = 0; i < res.length(); i++)
	// {
	// 	conta += stoi(res.substr(i, 1));
	// }

	// cout << conta;

	//-----------------------------------PROBLEM 18----------------------------------------

	// std::vector<std::vector<int>> input;

	// input.push_back({75});
	// input.push_back({95, 64});
	// input.push_back({17, 47, 82});
	// input.push_back({18, 35, 87, 10,});
	// input.push_back({20, 4, 82, 47, 65});
	// input.push_back({19, 1, 23, 75, 3, 34,});
	// input.push_back({88, 2, 77, 73, 7, 63, 67});
	// input.push_back({99, 65, 4, 28, 6, 16, 70, 92});
	// input.push_back({41, 41, 26, 56, 83, 40, 80, 70, 33});
	// input.push_back({41, 48, 72, 33, 47, 32, 37, 16, 94, 29});
	// input.push_back({53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14});
	// input.push_back({70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57});
	// input.push_back({91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48});
	// input.push_back({63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31});
	// input.push_back({4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23});

	// std::cout << problem18(input);

	//-----------------------------------PROBLEM 21----------------------------------------

	//long long sum = 0;
	//
	//for (int i = 1; i < 10000; i++)
	//{
	//	if (i != somadedivisores2(i))
	//	{
	//		if (somadedivisores2(somadedivisores2(i)) == i)
	//			sum += i;
	//	}
	//}
	//
	//std::cout << sum;

	//-----------------------------------PROBLEM 23----------------------------------------

	//std::vector<int> abundant;

	//std::vector<int> combi;

	//for (int i = 1; i < 30123; i++)  //Gerar nÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Âºmeros abundantes, ou seja, numeros que sejam menores que a soma dos seus divisores
	//{

	//	if (somadedivisores(i) > i)
	//		abundant.push_back(i);

	//}

	//for (int i = 0; i < abundant.size(); i++)  //Gerar todas as somas de dois nÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Âºmeros abundantes
	//{

	//	for (int j = i; j < abundant.size(); j++)
	//	{
	//		combi.push_back(abundant[i] + abundant[j]);
	//	}

	//}

	//sort(combi.begin(), combi.end());

	//long long count = 0;

	//for (int i = 1; i <= 28123; i++)  //Somar todos os nÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Âºmeros que nÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o sejam somas de nÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Âºmeros abundantes
	//{

	//	if (!std::binary_search(combi.begin(), combi.end(), i))
	//	{
	//		count += i;
	//	}
	//

	//}

	//std::cout << count;

	//-----------------------------------PROBLEM 24----------------------------------------
	/*
	std::vector<long long> res = longNewNumPerms({ 0,1,2,3,4,5,6,7,8,9 });

	std::cout << res[1000000 - 1];

*/
	/*int myints[] = {0,1,2,3,4,5,6,7,8,9};

for (int i = 0; i < 1000000; ++i)
{
	std::next_permutation(myints,myints + 10);
}

for (int i = 0; i < 10; ++i)
{
	std::cout << myints[i];
}
*/
	//-----------------------------------PROBLEM 25----------------------------------------

	//std::vector<std::string> res = { 2,std::to_string(1) };

	//long long i = 1;

	//while (res[i].length() < 1000)
	//{
	//	i++;

	//	res.push_back(bigadd(res[i - 1], res[i - 2]));

	//}

	//std::cout << i + 1;

	//-----------------------------------PROBLEM 27----------------------------------------

	//int max = 0;
	//int amax = 0;
	//int bmax = 0;

	//for (int a = -999; a < 1000; a++)                             // n^2 + a*n + b ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â© a funÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o que retorna os valores primos consecutivos comeÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ando em n = 0.
	//{

	//	for (int b = 0; b < 1000; b++)
	//	{

	//		if (if_primo(b))
	//		{

	//			int j = 1;

	//			while (if_primo(pow(j, 2) + j*a + b))
	//			{
	//				j++;
	//			}

	//			if (j > max)
	//			{
	//				max = j;
	//				amax = a;
	//				bmax = b;
	//			}

	//		}

	//	}

	//}

	//cout << "n^2 + " << amax << "n + " << bmax << " | " << max << endl;
	//cout << "Resultado: " << amax*bmax;

	//-----------------------------------PROBLEM 28---------------------------------------

	//cout << problem28(1001001);

	//-----------------------------------PROBLEM 29---------------------------------------

	/*vector<double> res;


for (int a = 2; a <= 100; a++)
{
for (int b = 2; b <= 100; b++)
{

res.push_back(pow(a, b));

}
}



for (int i = 0; i < res.size(); i++)
{
for (int j = i+1; j < res.size(); j++)
{

if (res[i] == res[j])
{
res.erase(res.begin() + j);
}
}


}

cout << res.size();*/

	//-----------------------------------PROBLEM 32---------------------------------------

	//long long sum = 0;
	//std::string workstr;
	//long long lastnumber = 0;

	//for (int i = 1; i < 100000; i++)
	//{

	//	for (int j = 0; j < (divisores(i).size() / 2); j++)
	//	{
	//		workstr = "";
	//		workstr += std::to_string(divisores(i)[j]);
	//		workstr += (std::to_string(i / divisores(i)[j]));
	//		workstr += (std::to_string(i));

	//		if ((workstr.length() == 9) && (if_pandigital(workstr)))
	//		{
	//			if (lastnumber != i)
	//			{
	//				lastnumber = i;
	//				sum += i;
	//			}

	//			else
	//			{
	//				lastnumber = i;
	//				break;
	//			}

	//		}

	//	}

	//}

	//std::cout << sum;

	//-----------------------------------PROBLEM 33---------------------------------------

	//std::vector<int> num;
	//std::vector<int> den;

	//std::string workstr1;
	//std::string workstr2;

	//for (int i = 11; i < 100; i++)  //Iterador do numerador
	//{

	//	for (int j = i + 1; j < 100; j++)  //Iterador do denominador
	//	{

	//		workstr1 = std::to_string(i);
	//		workstr2 = std::to_string(j);

	//		if (workstr1.substr(1) == "0" && workstr2.substr(1) == "0")
	//		{
	//			continue;
	//		}

	//		for (int a = 0; a < 2; a++)
	//		{

	//			for (int b = 0; b < 2; b++)
	//			{
	//				if (workstr1.substr(a,1) == workstr2.substr(b, 1))
	//				{

	//					std::string workstr3 = workstr1;
	//					std::string workstr4 = workstr2;

	//					workstr3.erase(a, 1);
	//					workstr4.erase(b, 1);

	//					if ((double)stoi(workstr3) / stoi(workstr4) == (double)i / j)
	//					{
	//						num.push_back(stoi(workstr3));
	//						den.push_back(stoi(workstr4));
	//					}

	//				}
	//			}

	//		}
	//

	//	}

	//}

	//int num1 = 1;
	//int num2 = 1;

	//for (int i = 0; i < 4; i++)
	//{
	//	num1 *= num[i];
	//}

	//for (int i = 0; i < 4; i++)
	//{
	//	num2 *= den[i];
	//}

	//-----------------------------------PROBLEM 35---------------------------------------

	/*bool flag;

int count = 0;

int place;

std::vector<int> temp;

std::vector<int> primes = SieveOfEratosthenes(999999);

for (int i = 0; i < primes.size(); ++i)
{
	temp = problem35(primes[i]);

	for (int i = 0; i < temp.size(); ++i)
	{
		if (if_primo(temp[i]));
		{
			flag = true;
			break;
		}

	}

	if (!flag)
		count += temp.size();
}

std::cout << count;*/

	//std::vector<int> test = problem35(12345);

	//-----------------------------------PROBLEM 36---------------------------------------

	//std::string workstr;
	//long long sum = 0;

	//for (long long i = 1; i < 1000000; i++)
	//{

	//	workstr = std::bitset<32>(i).to_string();

	//	workstr = workstr.substr(workstr.find_first_of("1"));

	//	if (if_palindrome(i) && if_palindrome(workstr))
	//	{
	//		sum += i;
	//	}

	//}

	//std::cout << sum;

	//-----------------------------------PROBLEM 38---------------------------------------

	//for (int i = 5; i <= 9327 ; i++)
	//{
	//	if (problem38(i)!="")
	//	{
	//		std::cout << problem38(i) << std::endl;
	//	}
	//}

	//-----------------------------------PROBLEM 39---------------------------------------

	//int max = 0;
	//int place;
	//
	//for (int i = 10; i <= 1000 ; i++)
	//{
	//	if (numerodesolucoesproblem39(i) > max)
	//	{
	//		max = numerodesolucoesproblem39(i);
	//		place = i;
	//	}
	//}
	//
	//cout << place

	//-----------------------------------PROBLEM 40---------------------------------------

	//std::string constant = "0.";

	//for (int i = 1; constant.length() < 1000005; i++)
	//{
	//	constant += std::to_string(i);
	//}

	//std::string multi = "1";

	//multi = bigmultiply(multi, stoi(constant.substr(11,1)));
	//multi = bigmultiply(multi, stoi(constant.substr(101, 1)));
	//multi = bigmultiply(multi, stoi(constant.substr(1001, 1)));
	//multi = bigmultiply(multi, stoi(constant.substr(10001, 1)));
	//multi = bigmultiply(multi, stoi(constant.substr(100001, 1)));
	//multi = bigmultiply(multi, stoi(constant.substr(1000001, 1)));

	//std::cout << multi;

	//-----------------------------------PROBLEM 41---------------------------------------

	/*long long max = 0;

std::vector<long long> primos = SieveOfEratosthenes(999999999);

for (long long i = primos.size() - 1;; i--)
{

if (if_pandigital(primos[i]))
{
std::cout << primos[i];
break;
}

}*/

	//-----------------------------------PROBLEM 42---------------------------------------

	//ifstream file("c:/problem42.txt");

	//string input;

	//file >> input;

	//int a1 = 0;
	//int a2 = 0;
	//int b = -1;
	//long long sum = 0;

	//vector<string> words;

	//for (int i = 0; i < input.length(); i++)
	//{

	//	if (input.substr(i, 1) == ",")
	//	{
	//		b++;
	//		a1 = a2;
	//		a2 = i + 1;
	//		words.push_back(input.substr(a1 + 1, a2 - a1 - 3));
	//	}

	//}

	//for (int i = input.length()-2; ; i--)  //Last word
	//{
	//	if (input.substr(i,1)==",")
	//	{
	//		a1 = i+1;
	//		a2 = input.length()+1 ;
	//		words.push_back(input.substr(a1 + 1, a2 - a1 - 3));
	//		break;
	//	}
	//}

	//for (int i = 0; i < words.size(); i++)
	//{
	//	if (if_trianglenumber(namescore(words[i])))
	//	{
	//		sum++;
	//	}
	//}

	//cout << sum;

	//-----------------------------------PROBLEM 43---------------------------------------

	//std::vector<std::vector<int>> pandigital = permutations({ 0,1,2,3,4,5,6,7,8,9 });

	//std::vector<long long> primes = SieveOfEratosthenes(17);

	//bool flag;

	//long long count = 0;

	//long long temp = 0;

	//for (int i = 0; i < pandigital.size(); i++)
	//{
	//	flag = true;

	//	for (int j = 1; j < 8; j++)
	//	{

	//		//Calcular substring
	//		temp = 100 * pandigital[i][j];
	//		temp += 10 * pandigital[i][j + 1];
	//		temp += pandigital[i][j + 2];

	//		if (temp % primes[j - 1])
	//		{
	//			flag = false;
	//			break;
	//		}

	//	}

	//	if (flag)
	//	{
	//		temp = 0;

	//		for (int l = 0; l < 10; l++)
	//		{
	//			temp += pandigital[i][l] * pow(10, 10 - l - 1);
	//		}

	//		count += temp;
	//	}

	//}

	//std::cout << count;

	//-----------------------------------PROBLEM 44---------------------------------------

	/*long long sum = 0;
long long difference;
long long min = 100000000;

for (int i = 1; i < 500; i++)
{

for (int j = i + 1; j < 500; j++)
{
sum = numeropentagonal(i) + numeropentagonal(j);
difference = numeropentagonal(j) - numeropentagonal(i);

if (if_pentagonal(sum) && if_pentagonal(difference))
{
if (difference < min)
{
min = difference;
}
}

}

}


cout << min;*/

	//-----------------------------------PROBLEM 45--------------------------------------

	// Um nÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Âºmero triangular ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â© obrigatoriamente hexagonal. H(n) = T(2*n)

	//int ultimo = 0;
	//long long res = 0;

	//for (int i = 166;  ; i++)
	//{
	//
	//	res = 3 * i;
	//	res -= 1;
	//	res *= i;
	//	res /= 2;

	//	if (if_hexagonal(res))
	//	{
	//		std::cout << res;
	//		break;
	//	}

	//}

	//-----------------------------------PROBLEM 46---------------------------------------

	//ofstream file;
	//file.open("46.txt",ofstream::out | std::ofstream::app);
	//file.is_open();
	//
	//cout << file.is_open() << endl;
	//
	//	for (int i = 3; ; i+=2)
	//	{
	//		if (!(if_primo(i)))
	//		{
	//
	//			for (int j = 2; j <= i; j++)
	//			{
	//				if (if_primo(j))
	//				{
	//					for (int l = 1; l < i; l++)
	//					{
	//						if (i == j + 2 * pow(l, 2))
	//						{
	//							goto cicle;
	//						}
	//
	//					}
	//
	//
	//				}
	//				if (j == i)
	//				{
	//					cout << i;
	//					file << i;
	//					goto fim;
	//				}
	//			}
	//		}
	//	cicle:;
	//	}
	//
	//fim:;
	//	file.close();

	//-----------------------------------PROBLEM 47--------------------------------------

	// std::vector<int> primes = SieveOfEratosthenes(1000);

	// for (int i = 3; 100000; ++i)
	// {

	// 	std::vector<int> first = problem47(i, primes);
	// 	std::vector<int> second = problem47(i + 1, primes);
	// 	std::vector<int> third = problem47(i + 2, primes);
	// 	std::vector<int> fourth = problem47(i + 3, primes);

	// 	if (first.size() == 4 && second.size() == 4 && third.size() == 4 && fourth.size() == 4 && union_new(first, second).size() == 0 && union_new(second, third).size() == 0 && union_new(third, fourth).size() == 0)
	// 	{
	// 		std::cout << i;
	// 		break;
	// 	}

	// }

	//-----------------------------------PROBLEM 48---------------------------------------

	////std::string numero = std::to_string(1);

	////for (int i = 2; i <= 100; i++)
	////{
	////	numero = bigadd(numero, bigpower(std::to_string(i), i));
	////}

	//////std::cout << numero.substr(numero.length() - 11, 10);

	////std::cout << numero;

	//std::vector<int> numero = itov(1);

	//for (int i = 2; i <= 1000; i++)
	//{
	//	numero = bigadd2(numero, bigpower2(itov(i), i));
	//}
	//
	///*for (int i = 0; i < 10; i++)
	//{
	//	std::cout << numero[numero.size() - 1 - i];
	//}*/

	//vector_cout(numero);

	//-----------------------------------PROBLEM 49---------------------------------------

	std::vector<int> primes = SieveOfEratosthenes(10000);

	while (1)
	{

		if (primes.front() < 1000)
			primes.erase(primes.begin());
		else
			break;

	}

	int subtract;

	std::vector<long long> numeros;
	numeros.resize(3);

	for (int i = 0; i < primes.size(); i++)
	{
		numeros[0] = primes[i];

		if (primes[i] == 1487)
			continue;

		for (int j = i + 1; j < primes.size(); j++)
		{
			numeros[1] = primes[j];

			numeros[2] = primes[j] + primes[j] - primes[i];

			if (binary_search(primes.begin(), primes.end(), numeros[2]))
			{
				if (is_permutation(numeros))
				{
					for (int k = 0; k < 3; k++)
					{
						std::cout << numeros[k];
						goto fim;
					}

				}

			}

		}
	}

//-----------------------------------PROBLEM 50--------------------------------------

//std::vector<int> primes;

//for (int i = 2; i < 1000000; i++)
//{
//if (if_primo(i) == true)
//primes.push_back(i);

//}

//int max = 0;
//int conta = 0;
//int sum = 0;
//int place;

//for (int i = 0; i < primes.size(); i++)    //ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¯Ãƒâ€šÃ‚Â¿Ãƒâ€šÃ‚Â½ndice do primo para verificar o numero de somas de numeros primos consecutivos
//{

//	for (int j = 0; j < i; j++)   //NÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Âºmero inicial para comeÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ar a soma
//	{
//		sum = 0;
//		conta = 0;
//		//if (primes[i] == 97 && j==9)
//		//	cout << "coisas" << endl;
//		for (int l = j; sum < primes[i]; l++) //Iterador do indice de numeros primos para somar
//		{

//			sum += primes[l];
//			conta++;

//			if (sum==primes[i] && conta > max)
//			{
//				max = conta;
//				place = primes[i];
//			}

//		}

//	}

//}

//std::cout << place << " with " << max << " sums";

//-----------------------------------PROBLEM 52--------------------------------------

//std::vector<long long> numero;

//int i = 10;

//do
//{
//	numero.resize(0);
//	i++;

//	numero.push_back(i);

//	for (int j = 2; j <= 6; j++)
//	{
//		numero.push_back(j*i);
//	}


//} while (!is_permutation(numero));

//std::cout << i;


//-----------------------------------PROBLEM 55--------------------------------------

//int count = 0;

//for (int i = 1; i < 10000; i++)
//{

//	if (!problem55_2(i))
//	{
//		count++;
//	}

//}

//std::cout << count;

//-----------------------------------PROBLEM 56--------------------------------------

//std::string numero;
//std::string workstr;
//long long max = 0;

//for (int a = 2 ; a < 100; a++)
//{
//	numero = std::to_string(a);

//	for (int b = 2; b < 100; b++)
//	{

//		numero = bigmultiply(numero, a);

//		if (sum_digits(numero) > max)
//			max = sum_digits(numero);

//	}

//}

//std::cout << max;

//-----------------------------------PROBLEM 57--------------------------------------

//int count = 0;

//for (int i = 1; i <= 1000; i++)
//{

//	std::vector<std::string> coisas = problem57_3(i);

//	if (coisas[0].length() > coisas[1].length())
//	{
//		count++;
//	}

//}

//std::cout << count;

//-----------------------------------PROBLEM 58--------------------------------------

//long long res;
//double countprimo = 0;
//double countall = 1;
//int i = 1;

//do
//{
//	i += 2;

//	countall += 4;

//	// a = 1

//	res = i*i - 1 * (i - 1);
//	if (isPrime(res))
//		countprimo++;

//	// a = 2

//	res = i*i - 2 * (i - 1);
//	if (isPrime(res))
//		countprimo++;

//	// a = 3

//	res = i*i - 3 * (i - 1);
//	if (isPrime(res))
//		countprimo++;

//} while (countprimo / countall > 0.1);

//std::cout << i;

//-----------------------------------PROBLEM 60--------------------------------------

//std::vector<long long> primes = SieveOfEratosthenes(1000);

//std::vector<int> primes2(5, 0);

//for (int i = 0; i < primes.size(); i++)
//{
//	primes2[0] = primes[i];

//	for (int j = i + 1; j < primes.size(); j++)
//	{
//		primes2[1] = primes[j];

//		for (int l = j + 1; l < primes.size(); l++)
//		{
//			primes2[2] = primes[l];

//			for (int k = l + 1; k < primes.size(); k++)
//			{
//				primes2[3] = primes[k];

//				for (int h = k + 1; h < primes.size(); h++)
//				{
//					primes2[4] = primes[h];

//					if (problem60_2(primes2))
//					{

//						int sum = 0;

//						for (int a = 0; a < primes2.size(); a++)
//						{

//							sum += primes2[a];

//						}

//						std::cout << sum;

//						goto fim;
//					}

//				}

//			}

//		}

//	}

//}


// std::vector<int> primes = SieveOfEratosthenes(5000);

// primes.erase(primes.begin());
// primes.erase(primes.begin() + 2);

// std::vector<int> primes2;

// for (int i = 0; i < 30000; i++)
// {
// 	primes2.push_back(primes[i]);

// 	for (int j = i + 1; j < primes.size(); j++)
// 	{

// 		if (problem60_3(primes2, primes[j], primes))
// 		{
// 			primes2.push_back(primes[j]);

// 			for (int l = j + 1; l < primes.size(); l++)
// 			{

// 				if (problem60_3(primes2, primes[l], primes))
// 				{
// 					primes2.push_back(primes[l]);

// 					for (int k = l + 1; k < primes.size(); k++)
// 					{

// 						if (problem60_3(primes2, primes[k], primes))
// 						{
// 							primes2.push_back(primes[k]);

// 							for (int h = k + 1; h < primes.size(); h++)
// 							{

// 								if (problem60_3(primes2, primes[h], primes))
// 								{

// 									int sum = 0;

// 									for (int a = 0; a < primes2.size(); a++)
// 									{

// 										sum += primes2[a];

// 									}

// 									sum += primes[h];

// 									std::cout << sum;

// 									goto fim;
// 								}

// 							}

// 							primes2.resize(primes2.size() - 1);
// 						}

// 					}

// 					primes2.resize(primes2.size() - 1);
// 				}

// 			}

// 			primes2.resize(primes2.size() - 1);
// 		}

// 	}

// 	primes2.resize(primes2.size() - 1);
// }


//-----------------------------------PROBLEM 61--------------------------------------


	//std::vector<std::vector<int>> P;
	//P.resize(6);

	//int tempadd, tempcount;

	//// Gerar os nÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Âºmeros de P
	//tempadd = 0;
	//tempcount = 1;
	//while (tempadd < 10000)
	//{
	//	tempadd += tempcount;
	//	if (tempadd > 999)
	//		P[0].push_back(tempadd);
	//	tempadd += tempcount;
	//	tempcount += 1;
	//}

	//tempadd = 0;
	//tempcount = 1;
	//while (tempadd < 10000)
	//{
	//	if (tempadd > 999)
	//		P[1].push_back(tempadd);
	//	tempadd += tempcount;
	//	tempcount += 2;
	//}

	//tempadd = 0;
	//tempcount = 1;
	//while (tempadd < 10000)
	//{
	//	if (tempadd > 999)
	//		P[2].push_back(tempadd);
	//	tempadd += tempcount;
	//	tempcount += 3;
	//}

	//tempadd = 0;
	//tempcount = 1;
	//while (tempadd < 10000)
	//{
	//	if (tempadd > 999)
	//		P[3].push_back(tempadd);
	//	tempadd += tempcount;
	//	tempcount += 4;
	//}

	//tempadd = 0;
	//tempcount = 1;
	//while (tempadd < 10000)
	//{
	//	if (tempadd > 999)
	//		P[4].push_back(tempadd);
	//	tempadd += tempcount;
	//	tempcount += 5;
	//}

	//tempadd = 0;
	//tempcount = 1;
	//while (tempadd < 10000)
	//{
	//	if (tempadd > 999)
	//		P[5].push_back(tempadd);
	//	tempadd += tempcount;
	//	tempcount += 6;
	//}


	//std::vector<bool> flags(5, true);

	//int temp1, temp2, sum;

	//for (int i = 0; i < P[5].size(); i++)
	//{
	//	temp1 = P[5][i];
	//	temp2 = temp1;
	//	sum = 0;

	//	flags = {true, true, true, true, true};

	//	while (1)
	//	{
	//	next:


	//		if (flags[0])
	//		{
	//			for (int j = 0; j < P[0].size(); j++)
	//			{

	//				if (temp2 % 100 == P[0][j] / 100)
	//				{
	//					temp2 = P[0][j];
	//					flags[0] = false;
	//					sum += temp2;
	//					goto next;
	//				}

	//			}
	//		}

	//		if (flags[1])
	//		{
	//			for (int j = 0; j < P[1].size(); j++)
	//			{

	//				if (temp2 % 100 == P[1][j] / 100)
	//				{
	//					temp2 = P[1][j];
	//					flags[1] = false;
	//					sum += temp2;
	//					goto next;
	//				}

	//			}
	//		}

	//		if (flags[2])
	//		{
	//			for (int j = 0; j < P[2].size(); j++)
	//			{

	//				if (temp2 % 100 == P[2][j] / 100)
	//				{
	//					temp2 = P[2][j];
	//					flags[2] = false;
	//					sum += temp2;
	//					goto next;
	//				}

	//			}
	//		}

	//		if (flags[3])
	//		{
	//			for (int j = 0; j < P[3].size(); j++)
	//			{

	//				if (temp2 % 100 == P[3][j] / 100)
	//				{
	//					temp2 = P[3][j];
	//					flags[3] = false;
	//					sum += temp2;
	//					goto next;
	//				}

	//			}
	//		}

	//		if (flags[4])
	//		{
	//			for (int j = 0; j < P[4].size(); j++)
	//			{

	//				if (temp2 % 100 == P[4][j] / 100)
	//				{
	//					temp2 = P[4][j];
	//					flags[4] = false;
	//					sum += temp2;
	//					goto next;
	//				}

	//			}
	//		}

	//		//if (flags[5])
	//		//{
	//		//	for (int j = 0; j < P[5].size(); j++)
	//		//	{

	//		//		if (temp2 % 100 == P[5][j] / 100)
	//		//		{
	//		//			temp2 = P[5][j];
	//		//			flags[5] = false;
	//		//			sum += temp2;
	//		//			goto next;
	//		//		}

	//		//	}
	//		//}

	//		int a = 0;


	//		for (int i = 0; i < flags.size(); i++)
	//		{
	//			if (flags[i])
	//				goto flagsnotzero;
	//		}

	//		if (temp2 % 100 == temp1 / 100)
	//			std::cout << sum;

	//		//...
	//	flagsnotzero:
	//		break;
	//	}

	//}

	//problem61();


	//-----------------------------------PROBLEM 62--------------------------------------

	//std::vector<long long> cubes;

	//for (long long i = 1; i < 10000; i++)
	//{
	//	cubes.push_back(i*i*i);
	//}

	//std::vector<std::vector<long long>> temps;

	//std::vector<std::vector<std::vector<long long>>> adds;

	//adds.resize(numlength(cubes.back()) + 1);

	//long long temp;

	//std::vector<long long> row;

	//std::vector<long long> row2(10, 0);

	//int length;

	//for (int i = 0; i < cubes.size(); i++)
	//{

	//	for (int j = 0; j < 9; j++)
	//	{
	//		row2[j] = 0;
	//	}

	//	temp = cubes[i];

	//	row.clear();

	//	length = 0;

	//	while (temp)
	//	{
	//		if (temp % 10)
	//			row.push_back(temp % 10);

	//		length++;
	//		temp /= 10;
	//	}

	//	for (int j = 0; j < row.size(); j++)
	//	{
	//		row2[row[j] - 1]++;
	//	}

	//	row2[9] = cubes[i];
	//	adds[length].push_back(row2);

	//}

	//int count = 0;


	//bool flag;

	//for (int i = 2; i < adds.size(); i++)
	//{

	//	while (adds[i].size() != 0)
	//	{
	//		flag = true;

	//		temps.push_back(adds[i][0]);
	//		temps.back().push_back(0);

	//		for (int l = 1; l < adds[i].size(); l++)
	//		{
	//			flag = true;



	//			for (int k = 0; k < 9; k++)
	//			{
	//				if (adds[i][0][k] != adds[i][l][k])
	//				{
	//					flag = false;
	//					break;
	//				}

	//			}

	//			if (flag)
	//			{
	//				temps.push_back(adds[i][l]);
	//				temps.back().push_back(l);
	//			}

	//			if (temps.size() == 5)
	//			{

	//				double min = 1e23;

	//				for (int j = 0; j < temps.size(); j++)
	//				{
	//					if (temps[j][9] < min)
	//						min = temps[j][9];
	//				}

	//				std::cout << min;

	//				goto fim;

	//			}

	//		}


	//		for (int j = 0; j < temps.size(); j++)
	//		{
	//			adds[i].erase(adds[i].begin() + temps[j].back() - j);
	//		}

	//		temps.clear();

	//	}

	//}


	//-----------------------------------PROBLEM 63--------------------------------------

	//std::string val;
	//int a = 2;

	//std::vector<std::string> res;

	//for (int i = 1; i < 10; i++)
	//{
	//	val = std::to_string(i);

	//	for (int j = 1; j < 50; j++)
	//	{

	//		if (val.length() == j)
	//		{
	//			res.push_back(val);
	//		}

	//		val = bigmultiply(val, i);

	//	}

	//}

	//std::cout << res.size();

	//-----------------------------------PROBLEM 64--------------------------------------

	//int count = 0;

	//for (int i = 2; i <= 10000; i++)
	//{

	//	if (sqrt(i) != (int)sqrt(i))
	//	{

	//		if (problem64(i).size() % 2)
	//		{
	//			count++;
	//		}

	//	}

	//}

	//std::cout << count;

	//-----------------------------------PROBLEM 65--------------------------------------

	// std::vector<std::string> res = problem65(100);

	// int count = 0;

	// for (int i = 0; i < res[0].length(); i++)
	// {
	// 	count += stoi(res[0].substr(i, 1));
	// }

	// std::cout << count;

	//-----------------------------------PROBLEM 69--------------------------------------

	//int max = 0;


	//double temp;
	//std::vector<long long> primos = SieveOfEratosthenes(1000);

	////127

	//for (int i = 1; i < 15; i++)
	//{

	//	std::cout << i << " " << euler_totient(i * 127) << " " << (double)i / euler_totient(i * 127) << "\n";

	//}





	//-----------------------------------PROBLEM 70--------------------------------------

	//double min = 999;

	//int temp;

	//int res;

	//for (int i = 1; i < 10000000; i++)
	//{
	//	temp = euler_totient(i);

	//	if ((double)i / temp < min)
	//	{

	//		if (is_permutation({i,temp}))
	//		{
	//			min = (double)i / temp;
	//			res = i;
	//		}

	//	}

	//}

	//std::cout << res;

	//-----------------------------------PROBLEM 71--------------------------------------

	//int n;

	//double last = 2.0 / 5;

	//int res;

	//for (int d = 2; d <= 1000000; d++)
	//{

	//	for (n = last * d; n < (3.0 / 7) * d; n++)
	//	{
	//		if ((double)n / d > last)
	//		{
	//			last = (double)n / d;
	//			res = n;
	//		}
	//	}

	//}

	//std::cout << res;


	//-----------------------------------PROBLEM 72--------------------------------------


	// 	long long count = 0;

	// 	int temp;

	// 	int count2 = 0;

	// 	std::vector<int> primes = SieveOfEratosthenes(1000000);

	// 	std::vector<long long> divd;

	// //Test
	// 	for (int d = 2; d <= 1000000; d++)
	// 	{

	// 		divd.clear();

	// 	for (int i = 0; primes[i] <= d/2; i++) // divd contÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â©m agora apenas os divisores primos de d.
	// 	{
	// 		if (d % primes[i] == 0)
	// 		{
	// 			divd.push_back(primes[i]);
	// 		}
	// 	}

	// 	for (int n = 2; n < d; n++)
	// 	{

	// 		for (int j = 0; j < divd.size(); j++)	// Verificar se n ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â© divisivel por qualquer um dos divisores de d de modo a averiguar se forma uma fraÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o reduzida
	// 		{

	// 			if (n % divd[j] == 0) // Se for divisivel por qualquer um dos divisores de d, entÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o seguir para o numerador seguinte.
	// 				goto next_n;

	// 		}

	// 		count++;

	// 		next_n:;
	// 	}

	// 	count++;

	// }



	// Original
	//for (int d = 2; d <= 6000; d++)
	//{
	//	divd = divisores(d);
	//	multiplos.clear();

	//	for (int i = 0; i < divd.size(); i++) // divd contÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â©m agora apenas os divisores primos de d.
	//	{
	//		if (!if_primo(divd[i]))
	//		{
	//			divd.erase(divd.begin() + i);
	//			i--;
	//		}
	//	}

	//	for (int i = 0; i < divd.size(); i++)
	//	{
	//			temp = divd[i] * 2;

	//			for (int j = 3; temp < d; j++)
	//			{

	//				if (!std::binary_search(multiplos.begin(), multiplos.end(), temp))
	//					multiplos.insert(std::lower_bound(multiplos.begin(), multiplos.end(), temp), temp);

	//				temp = divd[i] * j;

	//			}
	//
	//	}

	//	count += d - multiplos.size() - divd.size() - 1;

	//}

	//std::cout << count;

	//-----------------------------------PROBLEM 73--------------------------------------

	// std::vector<long long> divd;

	// int count = 0;

	// for (int d = 2; d <= 12000; d++)
	// {
	// 	divd = divisores(d);

	// 	for (int i = 0; i < divd.size(); i++)
	// 	{
	// 		if (!if_primo(divd[i]))
	// 			divd.erase(divd.begin() + i);
	// 	}

	// 	for (int n = ceil((double)d / 3 + 0.1) ; n < 0.5 * d; n++)
	// 	{
	
	// 		for (int j = 0; j < divd.size(); j++) // Verificar se ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â© divisivel por qualquer um dos divisores de d de modo a averiguar se forma uma fraÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o reduzida
	// 		{
	
	// 			if (n % divd[j] == 0) // Se for divisivel por qualquer um dos divisores de d, entÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o seguir para o numerador seguinte.
	// 				goto next_n;
	// 		}

	// 		count++;


	// 	next_n: ;

	// 	}

	
	// }

	// std::cout << count;

	//-----------------------------------PROBLEM 74--------------------------------------

	//int max = 0;

	//for (int i = 1; i < 1000000; i++)
	//{
	//	if (num_chains_2(i) == 60)
	//	{
	//		max++;
	//	}
	//}

	//std::cout << max;

	//-----------------------------------PROBLEM 85--------------------------------------

	// int limit = 2000000;
	// int h_limit = (-1 + sqrt(1 + 8*limit))/2;
	// int w_res;
	// int h_res;
	// int last = 2000000;

	// for (int i = 2; i < h_limit + 2; ++i)
	// {

	// 	for (int j = i; j < h_limit + 2; ++j)
	// 	{

	// 		if (abs(limit - problem85(i,j)) < last)
	// 		{
	// 			last = abs(limit - problem85(i,j));
	// 			w_res = i;
	// 			h_res = j;
	// 		}

	// 	}

	// }

	// std::cout << (w_res * h_res);

	//-----------------------------------PROBLEM 87--------------------------------------

		// int max = 50000000;

		// std::vector<int> primes = SieveOfEratosthenes(ceil(sqrt(max)));

		// std::vector<int> acc;

		// int sum = 0;

		// int temp1,temp2,temp3;

		// int count = 0;

		// for (int i = 0; primes[i] < ceil(pow(max,(double)1/4)); ++i)
		// {
		// 	//sum = primes[i] * primes[i];

		// 	for (int j = 0; primes[j] < ceil(pow(max,(double)1/3)); ++j)
		// 	{
		// 		//temp2 = primes[j] * primes[j] * primes[j];

		// 		//sum += temp2;

		// 		for (int l = 0; l < primes.size() ; ++l)
		// 		{
		// 			//temp3 = primes[l] * primes[l] * primes[l] * primes[l];

		// 			sum = (primes[l] * primes[l]) + (primes[j] * primes[j] * primes[j]) + (primes[i] * primes[i] * primes[i] * primes[i]);
		// 			//sum += temp3;

		// 			if (sum < max)
		// 				acc.push_back(sum);



		// 			//sum -= temp3;
		// 		}

		// 		//sum -= temp2;
		// 	}

		// }

		// sort( acc.begin(), acc.end() );
		// acc.erase( unique( acc.begin(), acc.end() ), acc.end() );

		// std::cout << acc.size();


	//-----------------------------------PROBLEM 89--------------------------------------

	// std::vector<std::string> input = {"MMMMDCLXXII","MMDCCCLXXXIII","MMMDLXVIIII","MMMMDXCV","DCCCLXXII","MMCCCVI","MMMCDLXXXVII","MMMMCCXXI","MMMCCXX","MMMMDCCCLXXIII","MMMCCXXXVII","MMCCCLXXXXIX","MDCCCXXIIII","MMCXCVI","CCXCVIII","MMMCCCXXXII","MDCCXXX","MMMDCCCL","MMMMCCLXXXVI","MMDCCCXCVI","MMMDCII","MMMCCXII","MMMMDCCCCI","MMDCCCXCII","MDCXX","CMLXXXVII","MMMXXI","MMMMCCCXIV","MLXXII","MCCLXXVIIII","MMMMCCXXXXI","MMDCCCLXXII","MMMMXXXI","MMMDCCLXXX","MMDCCCLXXIX","MMMMLXXXV","MCXXI","MDCCCXXXVII","MMCCCLXVII","MCDXXXV","CCXXXIII","CMXX","MMMCLXIV","MCCCLXXXVI","DCCCXCVIII","MMMDCCCCXXXIV","CDXVIIII","MMCCXXXV","MDCCCXXXII","MMMMD","MMDCCLXIX","MMMMCCCLXXXXVI","MMDCCXLII","MMMDCCCVIIII","DCCLXXXIIII","MDCCCCXXXII","MMCXXVII","DCCCXXX","CCLXIX","MMMXI","MMMMCMLXXXXVIII","MMMMDLXXXVII","MMMMDCCCLX","MMCCLIV","CMIX","MMDCCCLXXXIIII","CLXXXII","MMCCCCXXXXV","MMMMDLXXXVIIII","MMMDCCCXXI","MMDCCCCLXXVI","MCCCCLXX","MMCDLVIIII","MMMDCCCLIX","MMMMCCCCXIX","MMMDCCCLXXV","XXXI","CDLXXXIII","MMMCXV","MMDCCLXIII","MMDXXX","MMMMCCCLVII","MMMDCI","MMMMCDLXXXIIII","MMMMCCCXVI","CCCLXXXVIII","MMMMCML","MMMMXXIV","MMMCCCCXXX","DCCX","MMMCCLX","MMDXXXIII","CCCLXIII","MMDCCXIII","MMMCCCXLIV","CLXXXXI","CXVI","MMMMCXXXIII","CLXX","DCCCXVIII","MLXVII","DLXXXX","MMDXXI","MMMMDLXXXXVIII","MXXII","LXI","DCCCCXLIII","MMMMDV","MMMMXXXIV","MDCCCLVIII","MMMCCLXXII","MMMMDCCXXXVI","MMMMLXXXIX","MDCCCLXXXI","MMMMDCCCXV","MMMMCCCCXI","MMMMCCCLIII","MDCCCLXXI","MMCCCCXI","MLXV","MMCDLXII","MMMMDXXXXII","MMMMDCCCXL","MMMMCMLVI","CCLXXXIV","MMMDCCLXXXVI","MMCLII","MMMCCCCXV","MMLXXXIII","MMMV","MMMV","DCCLXII","MMDCCCCXVI","MMDCXLVIII","CCLIIII","CCCXXV","MMDCCLXXXVIIII","MMMMDCLXXVIII","MMMMDCCCXCI","MMMMCCCXX","MMCCXLV","MMMDCCCLXIX","MMCCLXIIII","MMMDCCCXLIX","MMMMCCCLXIX","CMLXXXXI","MCMLXXXIX","MMCDLXI","MMDCLXXVIII","MMMMDCCLXI","MCDXXV","DL","CCCLXXII","MXVIIII","MCCCCLXVIII","CIII","MMMDCCLXXIIII","MMMDVIII","MMMMCCCLXXXXVII","MMDXXVII","MMDCCLXXXXV","MMMMCXLVI","MMMDCCLXXXII","MMMDXXXVI","MCXXII","CLI","DCLXXXIX","MMMCLI","MDCLXIII","MMMMDCCXCVII","MMCCCLXXXV","MMMDCXXVIII","MMMCDLX","MMMCMLII","MMMIV","MMMMDCCCLVIII","MMMDLXXXVIII","MCXXIV","MMMMLXXVI","CLXXIX","MMMCCCCXXVIIII","DCCLXXXV","MMMDCCCVI","LI","CLXXXVI","MMMMCCCLXXVI","MCCCLXVI","CCXXXIX","MMDXXXXI","MMDCCCXLI","DCCCLXXXVIII","MMMMDCCCIV","MDCCCCXV","MMCMVI","MMMMCMLXXXXV","MMDCCLVI","MMMMCCXLVIII","DCCCCIIII","MMCCCCIII","MMMDCCLXXXVIIII","MDCCCLXXXXV","DVII","MMMV","DCXXV","MMDCCCXCV","DCVIII","MMCDLXVI","MCXXVIII","MDCCXCVIII","MMDCLX","MMMDCCLXIV","MMCDLXXVII","MMDLXXXIIII","MMMMCCCXXII","MMMDCCCXLIIII","DCCCCLXVII","MMMCLXXXXIII","MCCXV","MMMMDCXI","MMMMDCLXXXXV","MMMCCCLII","MMCMIX","MMDCCXXV","MMDLXXXVI","MMMMDCXXVIIII","DCCCCXXXVIIII","MMCCXXXIIII","MMDCCLXXVIII","MDCCLXVIIII","MMCCLXXXV","MMMMDCCCLXXXVIII","MMCMXCI","MDXLII","MMMMDCCXIV","MMMMLI","DXXXXIII","MMDCCXI","MMMMCCLXXXIII","MMMDCCCLXXIII","MDCLVII","MMCD","MCCCXXVII","MMMMDCCIIII","MMMDCCXLVI","MMMCLXXXVII","MMMCCVIIII","MCCCCLXXIX","DL","DCCCLXXVI","MMDXCI","MMMMDCCCCXXXVI","MMCII","MMMDCCCXXXXV","MMMCDXLV","MMDCXXXXIV","MMD","MDCCCLXXXX","MMDCXLIII","MMCCXXXII","MMDCXXXXVIIII","DCCCLXXI","MDXCVIIII","MMMMCCLXXVIII","MDCLVIIII","MMMCCCLXXXIX","MDCLXXXV","MDLVIII","MMMMCCVII","MMMMDCXIV","MMMCCCLXIIII","MMIIII","MMMMCCCLXXIII","CCIII","MMMCCLV","MMMDXIII","MMMCCCXC","MMMDCCCXXI","MMMMCCCCXXXII","CCCLVI","MMMCCCLXXXVI","MXVIIII","MMMCCCCXIIII","CLXVII","MMMCCLXX","CCCCLXIV","MMXXXXII","MMMMCCLXXXX","MXL","CCXVI","CCCCLVIIII","MMCCCII","MCCCLVIII","MMMMCCCX","MCDLXXXXIV","MDCCCXIII","MMDCCCXL","MMMMCCCXXIII","DXXXIV","CVI","MMMMDCLXXX","DCCCVII","MMCMLXIIII","MMMDCCCXXXIII","DCCC","MDIII","MMCCCLXVI","MMMCCCCLXXI","MMDCCCCXVIII","CCXXXVII","CCCXXV","MDCCCXII","MMMCMV","MMMMCMXV","MMMMDCXCI","DXXI","MMCCXLVIIII","MMMMCMLII","MDLXXX","MMDCLXVI","CXXI","MMMDCCCLIIII","MMMCXXI","MCCIII","MMDCXXXXI","CCXCII","MMMMDXXXV","MMMCCCLXV","MMMMDLXV","MMMCCCCXXXII","MMMCCCVIII","DCCCCLXXXXII","MMCLXIV","MMMMCXI","MLXXXXVII","MMMCDXXXVIII","MDXXII","MLV","MMMMDLXVI","MMMCXII","XXXIII","MMMMDCCCXXVI","MMMLXVIIII","MMMLX","MMMCDLXVII","MDCCCLVII","MMCXXXVII","MDCCCCXXX","MMDCCCLXIII","MMMMDCXLIX","MMMMCMXLVIII","DCCCLXXVIIII","MDCCCLIII","MMMCMLXI","MMMMCCLXI","MMDCCCLIII","MMMDCCCVI","MMDXXXXIX","MMCLXXXXV","MMDXXX","MMMXIII","DCLXXIX","DCCLXII","MMMMDCCLXVIII","MDCCXXXXIII","CCXXXII","MMMMDCXXV","MMMCCCXXVIII","MDCVIII","MMMCLXXXXIIII","CLXXXI","MDCCCCXXXIII","MMMMDCXXX","MMMDCXXIV","MMMCCXXXVII","MCCCXXXXIIII","CXVIII","MMDCCCCIV","MMMMCDLXXV","MMMDLXIV","MDXCIII","MCCLXXXI","MMMDCCCXXIV","MCXLIII","MMMDCCCI","MCCLXXX","CCXV","MMDCCLXXI","MMDLXXXIII","MMMMDCXVII","MMMCMLXV","MCLXVIII","MMMMCCLXXVI","MMMDCCLXVIIII","MMMMDCCCIX","DLXXXXIX","DCCCXXII","MMMMIII","MMMMCCCLXXVI","DCCCXCIII","DXXXI","MXXXIIII","CCXII","MMMDCCLXXXIIII","MMMCXX","MMMCMXXVII","DCCCXXXX","MMCDXXXVIIII","MMMMDCCXVIII","LV","MMMDCCCCVI","MCCCII","MMCMLXVIIII","MDCCXI","MMMMDLXVII","MMCCCCLXI","MMDCCV","MMMCCCXXXIIII","MMMMDI","MMMDCCCXCV","MMDCCLXXXXI","MMMDXXVI","MMMDCCCLVI","MMDCXXX","MCCCVII","MMMMCCCLXII","MMMMXXV","MMCMXXV","MMLVI","MMDXXX","MMMMCVII","MDC","MCCIII","MMMMDCC","MMCCLXXV","MMDCCCXXXXVI","MMMMCCCLXV","CDXIIII","MLXIIII","CCV","MMMCMXXXI","CCCCLXVI","MDXXXII","MMMMCCCLVIII","MMV","MMMCLII","MCMLI","MMDCCXX","MMMMCCCCXXXVI","MCCLXXXI","MMMCMVI","DCCXXX","MMMMCCCLXV","DCCCXI","MMMMDCCCXIV","CCCXXI","MMDLXXV","CCCCLXXXX","MCCCLXXXXII","MMDCIX","DCCXLIIII","DXIV","MMMMCLII","CDLXI","MMMCXXVII","MMMMDCCCCLXIII","MMMDCLIIII","MCCCCXXXXII","MMCCCLX","CCCCLIII","MDCCLXXVI","MCMXXIII","MMMMDLXXVIII","MMDCCCCLX","MMMCCCLXXXX","MMMCDXXVI","MMMDLVIII","CCCLXI","MMMMDCXXII","MMDCCCXXI","MMDCCXIII","MMMMCLXXXVI","MDCCCCXXVI","MDV","MMDCCCCLXXVI","MMMMCCXXXVII","MMMDCCLXXVIIII","MMMCCCCLXVII","DCCXLI","MMCLXXXVIII","MCCXXXVI","MMDCXLVIII","MMMMCXXXII","MMMMDCCLXVI","MMMMCMLI","MMMMCLXV","MMMMDCCCXCIV","MCCLXXVII","LXXVIIII","DCCLII","MMMCCCXCVI","MMMCLV","MMDCCCXXXXVIII","DCCCXV","MXC","MMDCCLXXXXVII","MMMMCML","MMDCCCLXXVIII","DXXI","MCCCXLI","DCLXXXXI","MMCCCLXXXXVIII","MDCCCCLXXVIII","MMMMDXXV","MMMDCXXXVI","MMMCMXCVII","MMXVIIII","MMMDCCLXXIV","MMMCXXV","DXXXVIII","MMMMCLXVI","MDXII","MMCCCLXX","CCLXXI","DXIV","MMMCLIII","DLII","MMMCCCXLIX","MMCCCCXXVI","MMDCXLIII","MXXXXII","CCCLXXXV","MDCLXXVI","MDCXII","MMMCCCLXXXIII","MMDCCCCLXXXII","MMMMCCCLXXXV","MMDCXXI","DCCCXXX","MMMDCCCCLII","MMMDCCXXII","MMMMCDXCVIII","MMMCCLXVIIII","MMXXV","MMMMCDXIX","MMMMCCCX","MMMCCCCLXVI","MMMMDCLXXVIIII","MMMMDCXXXXIV","MMMCMXII","MMMMXXXIII","MMMMDLXXXII","DCCCLIV","MDXVIIII","MMMCLXXXXV","CCCCXX","MMDIX","MMCMLXXXVIII","DCCXLIII","DCCLX","D","MCCCVII","MMMMCCCLXXXIII","MDCCCLXXIIII","MMMDCCCCLXXXVII","MMMMCCCVII","MMMDCCLXXXXVI","CDXXXIV","MCCLXVIII","MMMMDLX","MMMMDXII","MMMMCCCCLIIII","MCMLXXXXIII","MMMMDCCCIII","MMDCLXXXIII","MDCCCXXXXIV","XXXXVII","MMMDCCCXXXII","MMMDCCCXLII","MCXXXV","MDCXXVIIII","MMMCXXXXIIII","MMMMCDXVII","MMMDXXIII","MMMMCCCCLXI","DCLXXXXVIIII","LXXXXI","CXXXIII","MCDX","MCCLVII","MDCXXXXII","MMMCXXIV","MMMMLXXXX","MMDCCCCXLV","MLXXX","MMDCCCCLX","MCDLIII","MMMCCCLXVII","MMMMCCCLXXIV","MMMDCVIII","DCCCCXXIII","MMXCI","MMDCCIV","MMMMDCCCXXXIV","CCCLXXI","MCCLXXXII","MCMIII","CCXXXI","DCCXXXVIII","MMMMDCCXLVIIII","MMMMCMXXXV","DCCCLXXV","DCCXCI","MMMMDVII","MMMMDCCCLXVIIII","CCCXCV","MMMMDCCXX","MCCCCII","MMMCCCXC","MMMCCCII","MMDCCLXXVII","MMDCLIIII","CCXLIII","MMMDCXVIII","MMMCCCIX","MCXV","MMCCXXV","MLXXIIII","MDCCXXVI","MMMCCCXX","MMDLXX","MMCCCCVI","MMDCCXX","MMMMDCCCCXCV","MDCCCXXXII","MMMMDCCCCXXXX","XCIV","MMCCCCLX","MMXVII","MLXXI","MMMDXXVIII","MDCCCCII","MMMCMLVII","MMCLXXXXVIII","MDCCCCLV","MCCCCLXXIIII","MCCCLII","MCDXLVI","MMMMDXVIII","DCCLXXXIX","MMMDCCLXIV","MDCCCCXLIII","CLXXXXV","MMMMCCXXXVI","MMMDCCCXXI","MMMMCDLXXVII","MCDLIII","MMCCXLVI","DCCCLV","MCDLXX","DCLXXVIII","MMDCXXXIX","MMMMDCLX","MMDCCLI","MMCXXXV","MMMCCXII","MMMMCMLXII","MMMMCCV","MCCCCLXIX","MMMMCCIII","CLXVII","MCCCLXXXXIIII","MMMMDCVIII","MMDCCCLXI","MMLXXIX","CMLXIX","MMDCCCXLVIIII","DCLXII","MMMCCCXLVII","MDCCCXXXV","MMMMDCCXCVI","DCXXX","XXVI","MMLXIX","MMCXI","DCXXXVII","MMMMCCCXXXXVIII","MMMMDCLXI","MMMMDCLXXIIII","MMMMVIII","MMMMDCCCLXII","MDCXCI","MMCCCXXIIII","CCCCXXXXV","MMDCCCXXI","MCVI","MMDCCLXVIII","MMMMCXL","MLXVIII","CMXXVII","CCCLV","MDCCLXXXIX","MMMCCCCLXV","MMDCCLXII","MDLXVI","MMMCCCXVIII","MMMMCCLXXXI","MMCXXVII","MMDCCCLXVIII","MMMCXCII","MMMMDCLVIII","MMMMDCCCXXXXII","MMDCCCCLXXXXVI","MDCCXL","MDCCLVII","MMMMDCCCLXXXVI","DCCXXXIII","MMMMDCCCCLXXXV","MMCCXXXXVIII","MMMCCLXXVIII","MMMDCLXXVIII","DCCCI","MMMMLXXXXVIIII","MMMCCCCLXXII","MMCLXXXVII","CCLXVI","MCDXLIII","MMCXXVIII","MDXIV","CCCXCVIII","CLXXVIII","MMCXXXXVIIII","MMMDCLXXXIV","CMLVIII","MCDLIX","MMMMDCCCXXXII","MMMMDCXXXIIII","MDCXXI","MMMDCXLV","MCLXXVIII","MCDXXII","IV","MCDLXXXXIII","MMMMDCCLXV","CCLI","MMMMDCCCXXXVIII","DCLXII","MCCCLXVII","MMMMDCCCXXXVI","MMDCCXLI","MLXI","MMMCDLXVIII","MCCCCXCIII","XXXIII","MMMDCLXIII","MMMMDCL","DCCCXXXXIIII","MMDLVII","DXXXVII","MCCCCXXIIII","MCVII","MMMMDCCXL","MMMMCXXXXIIII","MCCCCXXIV","MMCLXVIII","MMXCIII","MDCCLXXX","MCCCLIIII","MMDCLXXI","MXI","MCMLIV","MMMCCIIII","DCCLXXXVIIII","MDCLIV","MMMDCXIX","CMLXXXI","DCCLXXXVII","XXV","MMMXXXVI","MDVIIII","CLXIII","MMMCDLVIIII","MMCCCCVII","MMMLXX","MXXXXII","MMMMCCCLXVIII","MMDCCCXXVIII","MMMMDCXXXXI","MMMMDCCCXXXXV","MMMXV","MMMMCCXVIIII","MMDCCXIIII","MMMXXVII","MDCCLVIIII","MMCXXIIII","MCCCLXXIV","DCLVIII","MMMLVII","MMMCXLV","MMXCVII","MMMCCCLXXXVII","MMMMCCXXII","DXII","MMMDLV","MCCCLXXVIII","MMMCLIIII","MMMMCLXXXX","MMMCLXXXIIII","MDCXXIII","MMMMCCXVI","MMMMDLXXXIII","MMMDXXXXIII","MMMMCCCCLV","MMMDLXXXI","MMMCCLXXVI","MMMMXX","MMMMDLVI","MCCCCLXXX","MMMXXII","MMXXII","MMDCCCCXXXI","MMMDXXV","MMMDCLXXXVIIII","MMMDLXXXXVII","MDLXIIII","CMXC","MMMXXXVIII","MDLXXXVIII","MCCCLXXVI","MMCDLIX","MMDCCCXVIII","MDCCCXXXXVI","MMMMCMIV","MMMMDCIIII","MMCCXXXV","XXXXVI","MMMMCCXVII","MMCCXXIV","MCMLVIIII","MLXXXIX","MMMMLXXXIX","CLXXXXIX","MMMDCCCCLVIII","MMMMCCLXXIII","MCCCC","DCCCLIX","MMMCCCLXXXII","MMMCCLXVIIII","MCLXXXV","CDLXXXVII","DCVI","MMX","MMCCXIII","MMMMDCXX","MMMMXXVIII","DCCCLXII","MMMMCCCXLIII","MMMMCLXV","DXCI","MMMMCLXXX","MMMDCCXXXXI","MMMMXXXXVI","DCLX","MMMCCCXI","MCCLXXX","MMCDLXXII","DCCLXXI","MMMCCCXXXVI","MCCCCLXXXVIIII","CDLVIII","DCCLVI","MMMMDCXXXVIII","MMCCCLXXXIII","MMMMDCCLXXV","MMMXXXVI","CCCLXXXXIX","CV","CCCCXIII","CCCCXVI","MDCCCLXXXIIII","MMDCCLXXXII","MMMMCCCCLXXXI","MXXV","MMCCCLXXVIIII","MMMCCXII","MMMMCCXXXIII","MMCCCLXXXVI","MMMDCCCLVIIII","MCCXXXVII","MDCLXXV","XXXV","MMDLI","MMMCCXXX","MMMMCXXXXV","CCCCLIX","MMMMDCCCLXXIII","MMCCCXVII","DCCCXVI","MMMCCCXXXXV","MDCCCCXCV","CLXXXI","MMMMDCCLXX","MMMDCCCIII","MMCLXXVII","MMMDCCXXIX","MMDCCCXCIIII","MMMCDXXIIII","MMMMXXVIII","MMMMDCCCCLXVIII","MDCCCXX","MMMMCDXXI","MMMMDLXXXIX","CCXVI","MDVIII","MMCCLXXI","MMMDCCCLXXI","MMMCCCLXXVI","MMCCLXI","MMMMDCCCXXXIV","DLXXXVI","MMMMDXXXII","MMMXXIIII","MMMMCDIV","MMMMCCCXLVIII","MMMMCXXXVIII","MMMCCCLXVI","MDCCXVIII","MMCXX","CCCLIX","MMMMDCCLXXII","MDCCCLXXV","MMMMDCCCXXIV","DCCCXXXXVIII","MMMDCCCCXXXVIIII","MMMMCCXXXV","MDCLXXXIII","MMCCLXXXIV","MCLXXXXIIII","DXXXXIII","MCCCXXXXVIII","MMCLXXIX","MMMMCCLXIV","MXXII","MMMCXIX","MDCXXXVII","MMDCCVI","MCLXXXXVIII","MMMCXVI","MCCCLX","MMMCDX","CCLXVIIII","MMMCCLX","MCXXVIII","LXXXII","MCCCCLXXXI","MMMI","MMMCCCLXIV","MMMCCCXXVIIII","CXXXVIII","MMCCCXX","MMMCCXXVIIII","MCCLXVI","MMMCCCCXXXXVI","MMDCCXCIX","MCMLXXI","MMCCLXVIII","CDLXXXXIII","MMMMDCCXXII","MMMMDCCLXXXVII","MMMDCCLIV","MMCCLXIII","MDXXXVII","DCCXXXIIII","MCII","MMMDCCCLXXI","MMMLXXIII","MDCCCLIII","MMXXXVIII","MDCCXVIIII","MDCCCCXXXVII","MMCCCXVI","MCMXXII","MMMCCCLVIII","MMMMDCCCXX","MCXXIII","MMMDLXI","MMMMDXXII","MDCCCX","MMDXCVIIII","MMMDCCCCVIII","MMMMDCCCCXXXXVI","MMDCCCXXXV","MMCXCIV","MCMLXXXXIII","MMMCCCLXXVI","MMMMDCLXXXV","CMLXIX","DCXCII","MMXXVIII","MMMMCCCXXX","XXXXVIIII"};

	// int count = 0;

	// for (int i = 0; i < input.size(); ++i)
	// {
	// 	count += input[i].size() - inttoroman(Romantoint(input[i])).size();

	// }

	// std::cout << count;

	//-----------------------------------PROBLEM 92--------------------------------------

		//int max = 10000000;

		//int res = 0;

		//int count = 0;

		//int temp;

		//for (int i = 2; i < max ; ++i)
		//{
		//	temp = i;
		//	
		//	while (1)
		//	{
		//		count = 0;

		//		if (temp == 1)
		//			break;

		//		if (temp == 89)
		//		{
		//			res++;
		//			break;
		//		}

		//		while (temp)
		//		{
		//			count += (temp % 10) * (temp % 10);
		//			temp /= 10;
		//		}

		//		temp = count;
		//	}

		//}


		//std::cout << res;

	//-----------------------------------PROBLEM 94--------------------------------------

	//double area;

	//int b;
	//double s;

	//unsigned long long count = 0;
	//long long count2 = 0;

	//int perimetro;

	//int i;

	//for (i = 2; i < 333333333; i++)
	//{

	//	b = i - 1;  //triangulo quase equilatero por defeito;

	//	s = i + i + b;
	//	s /= 2;

	//	area = sqrt(s*(s - i)*(s - i)*(s - b));

	//	perimetro = i + i + b;

	//	if ((long long)area == area)
	//		count += perimetro;

	//	b = i + 1;  //triangulo quase equilatero por excesso;

	//	s += 1;

	//	area = sqrt(s*(s - i)*(s - i)*(s - b));
	//	perimetro = i + i + b;

	//	if ((long long)area == area && area > 0 && perimetro < 1000000000)
	//		count += i + i + b;
	//}

	//i++;

	//b = i - 1;  //triangulo quase equilatero por defeito;

	//s = i + i + b;
	//s /= 2;

	//area = sqrt(s*(s - i)*(s - i)*(s - b));

	//perimetro = i + i + b;

	//if ((long long)area == area)
	//	count += perimetro;

	//std::cout << count;


	//-----------------------------------PROBLEM 99--------------------------------------


	// std::vector<std::vector<int>> input = {{519432,525806},{632382,518061},{78864,613712},{466580,530130},{780495,510032},{525895,525320},{15991,714883},{960290,502358},{760018,511029},{166800,575487},{210884,564478},{555151,523163},{681146,515199},{563395,522587},{738250,512126},{923525,503780},{595148,520429},{177108,572629},{750923,511482},{440902,532446},{881418,505504},{422489,534197},{979858,501616},{685893,514935},{747477,511661},{167214,575367},{234140,559696},{940238,503122},{728969,512609},{232083,560102},{900971,504694},{688801,514772},{189664,569402},{891022,505104},{445689,531996},{119570,591871},{821453,508118},{371084,539600},{911745,504251},{623655,518600},{144361,582486},{352442,541775},{420726,534367},{295298,549387},{6530,787777},{468397,529976},{672336,515696},{431861,533289},{84228,610150},{805376,508857},{444409,532117},{33833,663511},{381850,538396},{402931,536157},{92901,604930},{304825,548004},{731917,512452},{753734,511344},{51894,637373},{151578,580103},{295075,549421},{303590,548183},{333594,544123},{683952,515042},{60090,628880},{951420,502692},{28335,674991},{714940,513349},{343858,542826},{549279,523586},{804571,508887},{260653,554881},{291399,549966},{402342,536213},{408889,535550},{40328,652524},{375856,539061},{768907,510590},{165993,575715},{976327,501755},{898500,504795},{360404,540830},{478714,529095},{694144,514472},{488726,528258},{841380,507226},{328012,544839},{22389,690868},{604053,519852},{329514,544641},{772965,510390},{492798,527927},{30125,670983},{895603,504906},{450785,531539},{840237,507276},{380711,538522},{63577,625673},{76801,615157},{502694,527123},{597706,520257},{310484,547206},{944468,502959},{121283,591152},{451131,531507},{566499,522367},{425373,533918},{40240,652665},{39130,654392},{714926,513355},{469219,529903},{806929,508783},{287970,550487},{92189,605332},{103841,599094},{671839,515725},{452048,531421},{987837,501323},{935192,503321},{88585,607450},{613883,519216},{144551,582413},{647359,517155},{213902,563816},{184120,570789},{258126,555322},{502546,527130},{407655,535678},{401528,536306},{477490,529193},{841085,507237},{732831,512408},{833000,507595},{904694,504542},{581435,521348},{455545,531110},{873558,505829},{94916,603796},{720176,513068},{545034,523891},{246348,557409},{556452,523079},{832015,507634},{173663,573564},{502634,527125},{250732,556611},{569786,522139},{216919,563178},{521815,525623},{92304,605270},{164446,576167},{753413,511364},{11410,740712},{448845,531712},{925072,503725},{564888,522477},{7062,780812},{641155,517535},{738878,512100},{636204,517828},{372540,539436},{443162,532237},{571192,522042},{655350,516680},{299741,548735},{581914,521307},{965471,502156},{513441,526277},{808682,508700},{237589,559034},{543300,524025},{804712,508889},{247511,557192},{543486,524008},{504383,526992},{326529,545039},{792493,509458},{86033,609017},{126554,589005},{579379,521481},{948026,502823},{404777,535969},{265767,554022},{266876,553840},{46631,643714},{492397,527958},{856106,506581},{795757,509305},{748946,511584},{294694,549480},{409781,535463},{775887,510253},{543747,523991},{210592,564536},{517119,525990},{520253,525751},{247926,557124},{592141,520626},{346580,542492},{544969,523902},{506501,526817},{244520,557738},{144745,582349},{69274,620858},{292620,549784},{926027,503687},{736320,512225},{515528,526113},{407549,535688},{848089,506927},{24141,685711},{9224,757964},{980684,501586},{175259,573121},{489160,528216},{878970,505604},{969546,502002},{525207,525365},{690461,514675},{156510,578551},{659778,516426},{468739,529945},{765252,510770},{76703,615230},{165151,575959},{29779,671736},{928865,503569},{577538,521605},{927555,503618},{185377,570477},{974756,501809},{800130,509093},{217016,563153},{365709,540216},{774508,510320},{588716,520851},{631673,518104},{954076,502590},{777828,510161},{990659,501222},{597799,520254},{786905,509727},{512547,526348},{756449,511212},{869787,505988},{653747,516779},{84623,609900},{839698,507295},{30159,670909},{797275,509234},{678136,515373},{897144,504851},{989554,501263},{413292,535106},{55297,633667},{788650,509637},{486748,528417},{150724,580377},{56434,632490},{77207,614869},{588631,520859},{611619,519367},{100006,601055},{528924,525093},{190225,569257},{851155,506789},{682593,515114},{613043,519275},{514673,526183},{877634,505655},{878905,505602},{1926,914951},{613245,519259},{152481,579816},{841774,507203},{71060,619442},{865335,506175},{90244,606469},{302156,548388},{399059,536557},{478465,529113},{558601,522925},{69132,620966},{267663,553700},{988276,501310},{378354,538787},{529909,525014},{161733,576968},{758541,511109},{823425,508024},{149821,580667},{269258,553438},{481152,528891},{120871,591322},{972322,501901},{981350,501567},{676129,515483},{950860,502717},{119000,592114},{392252,537272},{191618,568919},{946699,502874},{289555,550247},{799322,509139},{703886,513942},{194812,568143},{261823,554685},{203052,566221},{217330,563093},{734748,512313},{391759,537328},{807052,508777},{564467,522510},{59186,629748},{113447,594545},{518063,525916},{905944,504492},{613922,519213},{439093,532607},{445946,531981},{230530,560399},{297887,549007},{459029,530797},{403692,536075},{855118,506616},{963127,502245},{841711,507208},{407411,535699},{924729,503735},{914823,504132},{333725,544101},{176345,572832},{912507,504225},{411273,535308},{259774,555036},{632853,518038},{119723,591801},{163902,576321},{22691,689944},{402427,536212},{175769,572988},{837260,507402},{603432,519893},{313679,546767},{538165,524394},{549026,523608},{61083,627945},{898345,504798},{992556,501153},{369999,539727},{32847,665404},{891292,505088},{152715,579732},{824104,507997},{234057,559711},{730507,512532},{960529,502340},{388395,537687},{958170,502437},{57105,631806},{186025,570311},{993043,501133},{576770,521664},{215319,563513},{927342,503628},{521353,525666},{39563,653705},{752516,511408},{110755,595770},{309749,547305},{374379,539224},{919184,503952},{990652,501226},{647780,517135},{187177,570017},{168938,574877},{649558,517023},{278126,552016},{162039,576868},{658512,516499},{498115,527486},{896583,504868},{561170,522740},{747772,511647},{775093,510294},{652081,516882},{724905,512824},{499707,527365},{47388,642755},{646668,517204},{571700,522007},{180430,571747},{710015,513617},{435522,532941},{98137,602041},{759176,511070},{486124,528467},{526942,525236},{878921,505604},{408313,535602},{926980,503640},{882353,505459},{566887,522345},{3326,853312},{911981,504248},{416309,534800},{392991,537199},{622829,518651},{148647,581055},{496483,527624},{666314,516044},{48562,641293},{672618,515684},{443676,532187},{274065,552661},{265386,554079},{347668,542358},{31816,667448},{181575,571446},{961289,502320},{365689,540214},{987950,501317},{932299,503440},{27388,677243},{746701,511701},{492258,527969},{147823,581323},{57918,630985},{838849,507333},{678038,515375},{27852,676130},{850241,506828},{818403,508253},{131717,587014},{850216,506834},{904848,504529},{189758,569380},{392845,537217},{470876,529761},{925353,503711},{285431,550877},{454098,531234},{823910,508003},{318493,546112},{766067,510730},{261277,554775},{421530,534289},{694130,514478},{120439,591498},{213308,563949},{854063,506662},{365255,540263},{165437,575872},{662240,516281},{289970,550181},{847977,506933},{546083,523816},{413252,535113},{975829,501767},{361540,540701},{235522,559435},{224643,561577},{736350,512229},{328303,544808},{35022,661330},{307838,547578},{474366,529458},{873755,505819},{73978,617220},{827387,507845},{670830,515791},{326511,545034},{309909,547285},{400970,536363},{884827,505352},{718307,513175},{28462,674699},{599384,520150},{253565,556111},{284009,551093},{343403,542876},{446557,531921},{992372,501160},{961601,502308},{696629,514342},{919537,503945},{894709,504944},{892201,505051},{358160,541097},{448503,531745},{832156,507636},{920045,503924},{926137,503675},{416754,534757},{254422,555966},{92498,605151},{826833,507873},{660716,516371},{689335,514746},{160045,577467},{814642,508425},{969939,501993},{242856,558047},{76302,615517},{472083,529653},{587101,520964},{99066,601543},{498005,527503},{709800,513624},{708000,513716},{20171,698134},{285020,550936},{266564,553891},{981563,501557},{846502,506991},{334,1190800},{209268,564829},{9844,752610},{996519,501007},{410059,535426},{432931,533188},{848012,506929},{966803,502110},{983434,501486},{160700,577267},{504374,526989},{832061,507640},{392825,537214},{443842,532165},{440352,532492},{745125,511776},{13718,726392},{661753,516312},{70500,619875},{436952,532814},{424724,533973},{21954,692224},{262490,554567},{716622,513264},{907584,504425},{60086,628882},{837123,507412},{971345,501940},{947162,502855},{139920,584021},{68330,621624},{666452,516038},{731446,512481},{953350,502619},{183157,571042},{845400,507045},{651548,516910},{20399,697344},{861779,506331},{629771,518229},{801706,509026},{189207,569512},{737501,512168},{719272,513115},{479285,529045},{136046,585401},{896746,504860},{891735,505067},{684771,514999},{865309,506184},{379066,538702},{503117,527090},{621780,518717},{209518,564775},{677135,515423},{987500,501340},{197049,567613},{329315,544673},{236756,559196},{357092,541226},{520440,525733},{213471,563911},{956852,502490},{702223,514032},{404943,535955},{178880,572152},{689477,514734},{691351,514630},{866669,506128},{370561,539656},{739805,512051},{71060,619441},{624861,518534},{261660,554714},{366137,540160},{166054,575698},{601878,519990},{153445,579501},{279899,551729},{379166,538691},{423209,534125},{675310,515526},{145641,582050},{691353,514627},{917468,504026},{284778,550976},{81040,612235},{161699,576978},{616394,519057},{767490,510661},{156896,578431},{427408,533714},{254849,555884},{737217,512182},{897133,504851},{203815,566051},{270822,553189},{135854,585475},{778805,510111},{784373,509847},{305426,547921},{733418,512375},{732087,512448},{540668,524215},{702898,513996},{628057,518328},{640280,517587},{422405,534204},{10604,746569},{746038,511733},{839808,507293},{457417,530938},{479030,529064},{341758,543090},{620223,518824},{251661,556451},{561790,522696},{497733,527521},{724201,512863},{489217,528217},{415623,534867},{624610,518548},{847541,506953},{432295,533249},{400391,536421},{961158,502319},{139173,584284},{421225,534315},{579083,521501},{74274,617000},{701142,514087},{374465,539219},{217814,562985},{358972,540995},{88629,607424},{288597,550389},{285819,550812},{538400,524385},{809930,508645},{738326,512126},{955461,502535},{163829,576343},{826475,507891},{376488,538987},{102234,599905},{114650,594002},{52815,636341},{434037,533082},{804744,508880},{98385,601905},{856620,506559},{220057,562517},{844734,507078},{150677,580387},{558697,522917},{621751,518719},{207067,565321},{135297,585677},{932968,503404},{604456,519822},{579728,521462},{244138,557813},{706487,513800},{711627,513523},{853833,506674},{497220,527562},{59428,629511},{564845,522486},{623621,518603},{242689,558077},{125091,589591},{363819,540432},{686453,514901},{656813,516594},{489901,528155},{386380,537905},{542819,524052},{243987,557841},{693412,514514},{488484,528271},{896331,504881},{336730,543721},{728298,512647},{604215,519840},{153729,579413},{595687,520398},{540360,524240},{245779,557511},{924873,503730},{509628,526577},{528523,525122},{3509,847707},{522756,525555},{895447,504922},{44840,646067},{45860,644715},{463487,530404},{398164,536654},{894483,504959},{619415,518874},{966306,502129},{990922,501212},{835756,507474},{548881,523618},{453578,531282},{474993,529410},{80085,612879},{737091,512193},{50789,638638},{979768,501620},{792018,509483},{665001,516122},{86552,608694},{462772,530469},{589233,520821},{891694,505072},{592605,520594},{209645,564741},{42531,649269},{554376,523226},{803814,508929},{334157,544042},{175836,572970},{868379,506051},{658166,516520},{278203,551995},{966198,502126},{627162,518387},{296774,549165},{311803,547027},{843797,507118},{702304,514032},{563875,522553},{33103,664910},{191932,568841},{543514,524006},{506835,526794},{868368,506052},{847025,506971},{678623,515342},{876139,505726},{571997,521984},{598632,520198},{213590,563892},{625404,518497},{726508,512738},{689426,514738},{332495,544264},{411366,535302},{242546,558110},{315209,546555},{797544,509219},{93889,604371},{858879,506454},{124906,589666},{449072,531693},{235960,559345},{642403,517454},{720567,513047},{705534,513858},{603692,519870},{488137,528302},{157370,578285},{63515,625730},{666326,516041},{619226,518883},{443613,532186},{597717,520257},{96225,603069},{86940,608450},{40725,651929},{460976,530625},{268875,553508},{270671,553214},{363254,540500},{384248,538137},{762889,510892},{377941,538833},{278878,551890},{176615,572755},{860008,506412},{944392,502967},{608395,519571},{225283,561450},{45095,645728},{333798,544090},{625733,518476},{995584,501037},{506135,526853},{238050,558952},{557943,522972},{530978,524938},{634244,517949},{177168,572616},{85200,609541},{953043,502630},{523661,525484},{999295,500902},{840803,507246},{961490,502312},{471747,529685},{380705,538523},{911180,504275},{334149,544046},{478992,529065},{325789,545133},{335884,543826},{426976,533760},{749007,511582},{667067,516000},{607586,519623},{674054,515599},{188534,569675},{565185,522464},{172090,573988},{87592,608052},{907432,504424},{8912,760841},{928318,503590},{757917,511138},{718693,513153},{315141,546566},{728326,512645},{353492,541647},{638429,517695},{628892,518280},{877286,505672},{620895,518778},{385878,537959},{423311,534113},{633501,517997},{884833,505360},{883402,505416},{999665,500894},{708395,513697},{548142,523667},{756491,511205},{987352,501340},{766520,510705},{591775,520647},{833758,507563},{843890,507108},{925551,503698},{74816,616598},{646942,517187},{354923,541481},{256291,555638},{634470,517942},{930904,503494},{134221,586071},{282663,551304},{986070,501394},{123636,590176},{123678,590164},{481717,528841},{423076,534137},{866246,506145},{93313,604697},{783632,509880},{317066,546304},{502977,527103},{141272,583545},{71708,618938},{617748,518975},{581190,521362},{193824,568382},{682368,515131},{352956,541712},{351375,541905},{505362,526909},{905165,504518},{128645,588188},{267143,553787},{158409,577965},{482776,528754},{628896,518282},{485233,528547},{563606,522574},{111001,595655},{115920,593445},{365510,540237},{959724,502374},{938763,503184},{930044,503520},{970959,501956},{913658,504176},{68117,621790},{989729,501253},{567697,522288},{820427,508163},{54236,634794},{291557,549938},{124961,589646},{403177,536130},{405421,535899},{410233,535417},{815111,508403},{213176,563974},{83099,610879},{998588,500934},{513640,526263},{129817,587733},{1820,921851},{287584,550539},{299160,548820},{860621,506386},{529258,525059},{586297,521017},{953406,502616},{441234,532410},{986217,501386},{781938,509957},{461247,530595},{735424,512277},{146623,581722},{839838,507288},{510667,526494},{935085,503327},{737523,512167},{303455,548204},{992779,501145},{60240,628739},{939095,503174},{794368,509370},{501825,527189},{459028,530798},{884641,505363},{512287,526364},{835165,507499},{307723,547590},{160587,577304},{735043,512300},{493289,527887},{110717,595785},{306480,547772},{318593,546089},{179810,571911},{200531,566799},{314999,546580},{197020,567622},{301465,548487},{237808,559000},{131944,586923},{882527,505449},{468117,530003},{711319,513541},{156240,578628},{965452,502162},{992756,501148},{437959,532715},{739938,512046},{614249,519196},{391496,537356},{62746,626418},{688215,514806},{75501,616091},{883573,505412},{558824,522910},{759371,511061},{173913,573489},{891351,505089},{727464,512693},{164833,576051},{812317,508529},{540320,524243},{698061,514257},{69149,620952},{471673,529694},{159092,577753},{428134,533653},{89997,606608},{711061,513557},{779403,510081},{203327,566155},{798176,509187},{667688,515963},{636120,517833},{137410,584913},{217615,563034},{556887,523038},{667229,515991},{672276,515708},{325361,545187},{172115,573985},{13846,725685}};

	// int resindex;

	// double max = input[0][1]*log(input[0][0]);

	// for (int i = 0; i < input.size(); ++i)
	// {
	// 	if (input[i][1]*log(input[i][0]) > max)
	// 	{
	// 		max = input[i][1]*log(input[i][0]);
	// 		resindex = i;
	// 	}

	// }

	// std::cout <<  resindex + 1;


	//-----------------------------------PROBLEM 233--------------------------------------

	// int N = 80000;
	// int sum = 0;
	// int xmax = floor((1 + sqrt(2))*N/(double)2);
	// double y;
	
	// 	sum = 0;
	// 	for (double x = ceil((1-sqrt(2))*N/(double)2); x < (double)N/2; x++)
	// 	{
	// 		y = (N + sqrt(N*N + 4*x*N - 4*x*x))/(double)2;
	
	// 		if (y == (int)y)
	// 			sum++;
	// 	}
	
	// 	sum *= 4;

	// 	y = (N + sqrt(2*N*N))/(double)2;

	// 	if (y == (int)y)
	// 		sum += 2;

	// 	std::cout << "Soma = " << sum << '\n';
	
		fim: ;
	}
	
		double deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - begin).count() / (double)1e9 / maxRuns;

		std::cout << "\nFinished in : " << deltaTime << " seconds.\n";

		return 0;
}
