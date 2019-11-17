#include "GeneratorAAL.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

vector<string> names({ NAMES__ALL });

void gen_user_groups(uint64_t c_left, uint64_t c_right, vector<string> &left_users, vector<string> &right_users) {
	uint64_t count = (c_left + c_right)/names.size();
	vector<string> tempNames;

	for (uint64_t i = 0; i <= count; ++i) {
		for (string iter : names) {
			tempNames.push_back(iter + std::to_string(i));
		}
	}

	std::random_device rd;
	std::mt19937_64 randomEngine(rd());

	std::shuffle(tempNames.begin(), tempNames.end(), randomEngine);

	left_users.clear();
	left_users.insert(left_users.end(), &tempNames[0], &tempNames[c_left]);

	right_users.clear();
	right_users.insert(right_users.end(), &tempNames[c_left], &tempNames[c_left+c_right]);
}

std::stringstream write_comments(uint64_t no_of_comm, vector<string>& left_users, vector<string>& right_users) {
	std::stringstream buffer;
	int l_count = left_users.size(),
		r_count = right_users.size(),
		count = r_count + l_count;

	std::random_device rd;
	std::mt19937_64 randomEngine(rd());

	uint64_t seed;
	for (uint64_t i = 0; i < no_of_comm; ++i) {
		seed = randomEngine() % count;
		if (seed < l_count) {
			buffer << '#' << left_users[seed] << ": @" << right_users[randomEngine() % r_count] << '\n';
		}
		else {
			buffer << '#' << right_users[seed - (uint64_t)l_count] << ": @" << left_users[randomEngine() % l_count] << '\n';
		}
	}
	return buffer;
}

vector<string> gen_user_groups(uint64_t count) {
	uint64_t c_mul = count / names.size();
	vector<string> tempNames;

	for (uint64_t i = 0; i <= c_mul; ++i) {
		for (string iter : names) {
			tempNames.push_back(iter + std::to_string(i));
		}
	}

	std::random_device rd;
	std::mt19937_64 randomEngine(rd());

	std::shuffle(tempNames.begin(), tempNames.end(), randomEngine);

	tempNames.resize(count);

	return tempNames;
}

std::stringstream write_comments(uint64_t no_of_comm, vector<string>& users, uint64_t l_count) {
	std::stringstream buffer;
	uint64_t seed,
		count = users.size(),
		r_count;
	if (l_count >= count) {
		return buffer;
	}
	else {
		r_count = count - l_count;
	}
	
	std::random_device rd;
	std::mt19937_64 randomEngine(rd());

	for (uint64_t i = 0; i < no_of_comm; ++i) {
		seed = randomEngine() % count;
		if (seed < l_count) {
			buffer << '#' << users[seed] << ": @" << users[l_count + randomEngine() % r_count] << " <Wredny Komentarz>\n";
		} else {
			buffer << '#' << users[seed] << ": @" << users[randomEngine() % l_count] << " <Wredny Komentarz>\n";
		}
	}

	return buffer;
}

int main(){
	/*vector<string> left, right;
	gen_user_groups(1000000, 1000000, left, right);
	cout << write_comments(10000, left, right).str();*/

	uint64_t l_count = 10,
		r_count = 12;
	vector<string> users = gen_user_groups(l_count + r_count);
	cout << write_comments(l_count * r_count, users, l_count).str();

	return 0;
}
