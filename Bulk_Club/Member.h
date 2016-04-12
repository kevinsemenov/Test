
#ifndef MEMBER_H_
#define MEMBER_H_

#include <string>
#include "Date.h"

using namespace std;

const float SALES_TAX = 0.0825;

class Member
{
	public:
		Member();
		Member(string memberName, unsigned int memberID, string memberType,
			   Date membershipExpiration, double totalSpent);
		virtual ~Member();

		void SetName(string memberName);
		void SetID(unsigned int memberID);
		void SetType(string memberType);
		void SetExpiration(Date membershipExpiration);
		void SetSpent(double totalSpent);

		string GetName() const;
		unsigned int GetID() const;
		string GetType() const;
		Date GetExpiration() const;
		double GetSpent() const;

		virtual void Update();


	private:
		string name;
		unsigned int id;
		string type;
		Date expiration;
		double spent;
		float fee;

};



#endif /* MEMBER_H_ */
