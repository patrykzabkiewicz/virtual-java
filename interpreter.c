
#include "interpreter.h"
#include "y.tab.h"

int ex(nodeType * p) {
	int i=0;
	int wynik=0;

	if (!p)
		return 1;

	switch (p->type) {
	case typeCon:
		return p->value.con.value;
	case typeId:
		return sym[p->value.id.i];
	case typeOpr:
		switch (p->value.opr.oper) {
		case WHILE:
			while (ex(p->value.opr.op[0]))
				ex(p->value.opr.op[1]);

			return 0;

		case IF:
			if (ex(p->value.opr.op[0]))
				ex(p->value.opr.op[1]);
			else if (p->value.opr.nops > 2)
				ex(p->value.opr.op[2]);

			return 0;

		case PRINT:
			printf(
			       "%d\n",
			       ex(p->value.opr.op[0])
				);

			return 0;

		case ';':
			ex(p->value.opr.op[0]);

			return ex(p->value.opr.op[1]);

		case '=':
			return sym[p->value.opr.op[0]->value.id.i] =
				ex(p->value.opr.op[1]);

		case UMINUS:
			return -ex(p->value.opr.op[0]);

		case '+':
			return ex(p->value.opr.op[0])
				+
				ex(p->value.opr.op[1]);

		case '-':
			return ex(p->value.opr.op[0])
				-
				ex(p->value.opr.op[1]);

		case '*':
			return ex(p->value.opr.op[0])
				*
				ex(p->value.opr.op[1]);

		case '^':
			{
			wynik = ex(p->value.opr.op[0]);
			for(i=1; i < ex(p->value.opr.op[1]); i++) wynik *= ex(p->value.opr.op[0]);
			return wynik;
			}

		case '/':
			return ex(p->value.opr.op[0])
				/
				ex(p->value.opr.op[1]);


		case '<':
			return ex(p->value.opr.op[0])
				<
				ex(p->value.opr.op[1]);

		case '>':
			return ex(p->value.opr.op[0])
				>
				ex(p->value.opr.op[1]);
		case GE:
			return ex(p->value.opr.op[0])
				>=
				ex(p->value.opr.op[1]);

		case LE:
			return ex(p->value.opr.op[0])
				<=
				ex(p->value.opr.op[1]);

		case NE:
			return ex(p->value.opr.op[0])
				!=
				ex(p->value.opr.op[1]);

		case EQ:
			return ex(p->value.opr.op[0])
				==
				ex(p->value.opr.op[1]);
		}

	}


	return 0;
}
