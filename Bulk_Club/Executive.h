
#ifndef EXECUTIVE_H_
#define EXECUTIVE_H_

#include "Member.h"

class Executive: public Member
{
	public:
		Executive();
		Executive(string memberName, unsigned int memberID, string memberType,
				  Date membershipExpiration, double totalSpent);
		virtual ~Executive();

		virtual void Update();

	private:
		float rebate;
		float fee;
};


#endif /* EXECUTIVE_H_ */
