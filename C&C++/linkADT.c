include "linkADT.h"
//////////////////////////////////////////////////////////////////////////
void addLink(struct link *head, struct link *tail)
{
	struct link *p = (struct link *)calloc(1, sizeof(struct link));
	p->last = tail;
	p->next = head;
	tail->next = p;
	head->last = p;
}
//////////////////////////////////////////////////////////////////////////
void delLink(struct link *p)
{
	p->last->next = p->next;
	p->next->last = p->last;
	free(p);
}
//////////////////////////////////////////////////////////////////////////
void insertLink(struct link *p, struct link *index)
{
	index->next->last = p;
	p->next = index->next;
	index->next = p;
	p->last = index;
}
//////////////////////////////////////////////////////////////////////////
void clearLink(struct link *p)
{
	if (p->last == p->next)
		free(p);
	else
	{
		struct link *head = p;
		head = head->next;
		do
		{
			head = head->next;
			free(head->last);
		} while (head->next != p);
		free(head);
		free(p);
	}
}
