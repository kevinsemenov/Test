
#ifndef DATABASE_H_
#define DATABASE_H_

#include "Member.h"
#include <vector>
#include <iterator>
#include <algorithm>

class Database
{
	public:
		Database();
		~Database();

		void AddMember(Member *newMember);
		Member FindMember(unsigned int memberID) const;

	private:
		vector<Member*> memberList;
};

//sdfsl;dfjsl;fkjsl;dkfjsdl;fkj


#endif /* DATABASE_H_ */
