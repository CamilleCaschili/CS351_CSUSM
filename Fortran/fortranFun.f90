character(21) function concat_name(first, last) result(fullName)
    implicit none

    character(10), intent(in) :: first, last

    fullName = first // " " // last

end function concat_name


program fortranFun

    implicit none

    character(10) :: firstName, lastName
    character(21) :: concat_name, fullName

    integer(1) :: age, i

    real :: myGpa

    print '(A, I0)', "Enter your first name: "
    read (*,*) firstName

    print '(A, I0)', "Enter your last name: "
    read (*,*) lastName

    fullName = concat_name(trim(firstName), trim(lastName))

    print *
    print *, "Your name is: ", fullName
    print *

    print '(A, I0)', "Enter your age:"
    read (*,*) age

    do while (age < 0)
        print '(A, I0)', "Your age must be positive !"
        read (*,*) age
    end do
    
    print *
    print '(A, I0)', "Your are ", age
    print *


    do i = 0, 8
        myGpa = i * 0.5
        print '(A,F4.2)', "Your GPA is: ", myGpa
        call sleep(1)
    end do

    print *
    print *, fullName, ": Great ! Now I have a GPA of 4 ! I hope this course will not lower it ;)"

end program fortranFun


