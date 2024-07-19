/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:38:48 by junkwak           #+#    #+#             */
/*   Updated: 2024/06/29 17:45:52 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	gval = 10; //전역변수, gval 값 10으로설정

int	main(int argc, char **argv)
{
	pid_t	pid; // pid를 저장할변수 선언
	int	lval = 20; // lval 값을 20으로 초기화
	gval++, lval += 5; // gval = 11, lval = 25

	pid = fork(); //자식프로세스 생성, 메모리그대로가져가니 gval =11, lval = 25
	if (pid == 0) // 만약 pid가 0이면 실행. 자식프로세스는 fork의 반환값이 0. 자식p.c에서만실행
		gval += 2, lval += 2;
	else // 부모프레스에서만
		gval -= 2, lval -= 2;
	if (pid == 0) // 자식프로세스에서만
		printf("Child Proc: [%d, %d] \n", gval, lval); //13,27
	else//부모프레스에서만
		printf("Parent Proc: [%d, %d] \n", gval, lval);//9,23
	return (0);
}
