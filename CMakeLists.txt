cmake_minimum_required(VERSION 3.13)
project(cpp_primer_plus_demo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(p1)
include_directories(p10)
include_directories(p10/10.1)
include_directories(p10/10.10)
include_directories(p10/10.11.test1)
include_directories(p10/10.11.test2)
include_directories(p10/10.11.test3)
include_directories(p10/10.11.test4)
include_directories(p10/10.11.test5)
include_directories(p10/10.11.test6)
include_directories(p10/10.11.test7)
include_directories(p10/10.11.test8)
include_directories(p11)
include_directories(p11/11.1)
include_directories(p11/11.2)
include_directories(p11/11.3)
include_directories(p11/11.4)
include_directories(p11/11.5)
include_directories(p11/11.6)
include_directories(p11/11.7)
include_directories(p11/11.9)
include_directories(p11/11.9/test1)
include_directories(p11/11.9/test2)
include_directories(p11/11.9/test3)
include_directories(p11/11.9/test4)
include_directories(p11/11.9/test5)
include_directories(p11/11.9/test6)
include_directories(p11/11.9/test7)
include_directories(p12)
include_directories(p12/test1)
include_directories(p12/test10)
include_directories(p12/test2)
include_directories(p12/test3)
include_directories(p12/test4)
include_directories(p12/test5)
include_directories(p12/test6)
include_directories(p12/test7)
include_directories(p12/test8)
include_directories(p12/test9)
include_directories(p13)
include_directories(p13/test1)
include_directories(p13/test2)
include_directories(p13/test3)
include_directories(p13/test4)
include_directories(p13/test5)
include_directories(p13/test6)
include_directories(p13/test7)
include_directories(p13/test8)
include_directories(p13/test9)
include_directories(p14)
include_directories(p14/test1)
include_directories(p14/test10)
include_directories(p14/test11)
include_directories(p14/test12)
include_directories(p14/test13)
include_directories(p14/test14)
include_directories(p14/test2)
include_directories(p14/test3)
include_directories(p14/test4)
include_directories(p14/test5)
include_directories(p14/test6)
include_directories(p14/test7)
include_directories(p14/test8)
include_directories(p14/test9)
include_directories(p2)
include_directories(p3)
include_directories(p4)
include_directories(p5)
include_directories(p6)
include_directories(p7)
include_directories(p8)
include_directories(p9)
include_directories(p9/9.1)
include_directories(p9/9.10)
include_directories(p9/9.11)
include_directories(p9/9.12.test1)
include_directories(p9/9.12.test2)
include_directories(p9/9.12.test3)
include_directories(p9/9.12.test4)
include_directories(p9/9.2)
include_directories(p9/9.5)
include_directories(p9/9.7)
include_directories(p9/9.9)

add_executable(cpp_primer_plus_demo
        # p1/myfirst.cpp
       
        # p2/2.2.carrot.cpp 
        # p2/2.3.getinfo.cpp
        # p2/2.4.sqrt.cpp
        # p2/2.5.ourfunc.cpp
        # p2/2.6.converter.cpp

        # p3/3.1.climits.cpp
        # p3/3.10.arith.cpp
        # p3/3.11.divide.cpp
        # p3/3.12.modules.cpp
        # p3/3.13.assign.cpp
        # p3/3.2.exceed.cpp
        # p3/3.3.hexoct.cpp
        # p3/3.4.hexoct_show.cpp
        # p3/3.5.chartype.cpp
        # p3/3.6.morechar.cpp
        # p3/3.7.bondini.cpp
        # p3/3.7.utf8.cpp
        # p3/3.8.floatnum.cpp
        # p3/3.9.floatadd.cpp

        # p4/4.1.arrayone.cpp
        # p4/4.10.strtype4.cpp
        # p4/4.11.structur.cpp
        # p4/4.12.assgn_st.cpp
        # p4/4.13.arrstruc.cpp
        # p4/4.14.address.cpp
        # p4/4.15.point.cpp
        # p4/4.16.init_ptr.cpp
        # p4/4.17.use_new.cpp
        # p4/4.18.arraynew.cpp
        # p4/4.19.addptr.cpp
        # p4/4.2.string.cpp
        # p4/4.20.ptrstr.cpp
        # p4/4.21.newstrut.cpp
        # p4/4.22.delete.cpp
        # p4/4.23.mixtypes.cpp
        # p4/4.24.choices.cpp
        # p4/4.25.test1.cpp
        # p4/4.25.test16.numstr.cpp
        # p4/4.25.test17.cpp
        # p4/4.25.test8.cpp
        # p4/4.26.test1.cpp
        # p4/4.26.test2.cpp
        # p4/4.26.test3.cpp
        # p4/4.27.test4.cpp
        # p4/4.27.test5.cpp
        # p4/4.27.test6.cpp
        # p4/4.27.test7.cpp
        # p4/4.27.test8.cpp
        # p4/4.27.test9.cpp
        # p4/4.3.input_string.cpp
        # p4/4.4.input.string.cpp
        # p4/4.5.input.string.cpp
        # p4/4.6.numstr.cpp
        # p4/4.7.strtype1.cpp
        # p4/4.8.strtype2.cpp
        # p4/4.9.strtype3.cpp

        # p5/5.1.forloop.cpp
        # p5/5.10.equal.cpp
        # p5/5.11.compstr1.cpp
        # p5/5.12.comstr2.cpp
        # p5/5.13.while.cpp
        # p5/5.14.waiting.cpp
        # p5/5.16.textin1.cpp
        # p5/5.17.textin2.cpp
        # p5/5.18.textin3.cpp
        # p5/5.19.textin4.cpp
        # p5/5.2.num_test.cpp
        # p5/5.20.nested.cpp
        # p5/5.21.test6.cpp
        # p5/5.22.test1.cpp
        # p5/5.22.test10.cpp
        # p5/5.22.test2.cpp
        # p5/5.22.test3.cpp
        # p5/5.22.test4.cpp
        # p5/5.22.test5.cpp
        # p5/5.22.test6.cpp
        # p5/5.22.test7.cpp
        # p5/5.22.test8.cpp
        # p5/5.22.test9.cpp
        # p5/5.3.express.cpp
        # p5/5.4.formore.cpp
        # p5/5.5.bigstep.cpp
        # p5/5.6.forstr1.cpp
        # p5/5.7.plus_one.cpp
        # p5/5.8.block.cpp
        # p5/5.9.forstr2.cpp

        # p6/6.1.if.cpp
        # p6/6.10.switch.cpp
        # p6/6.11.switch_enum.cpp
        # p6/6.12.jump.cpp
        # p6/6.13.cinfish.cpp
        # p6/6.14.cingolf.cpp
        # p6/6.15.outfile.cpp
        # p6/6.16.sumafile.cpp
        # p6/6.17.test1.cpp
        # p6/6.17.test2.cpp
        # p6/6.17.test3.cpp
        # p6/6.17.test4.cpp
        # p6/6.17.test5.cpp
        # p6/6.17.test6.cpp
        # p6/6.17.test7.cpp
        # p6/6.17.test8.cpp
        # p6/6.17.test9.cpp
        # p6/6.2.ifelse.cpp
        # p6/6.3.ifelseif.cpp
        # p6/6.4.or.cpp
        # p6/6.5.and.cpp
        # p6/6.6.more_and.cpp
        # p6/6.7.not.cpp
        # p6/6.8.cctypes.cpp
        # p6/6.9.condit.cpp
        # p6/carinfo.txt
        # p6/donation_info.txt
        # p6/scores.text

        # p7/7.1.calling.cpp
        # p7/7.10.strgback.cpp
        # p7/7.11.travel.cpp
        # p7/7.12.atrctfun.cpp
        # p7/7.13.atrctptr.cpp
        # p7/7.14.topfive.cpp
        # p7/7.15.arrobj.cpp
        # p7/7.16.recus.cpp
        # p7/7.17.ruler.cpp
        # p7/7.18.fun_ptr.cpp
        # p7/7.19.arfupt.cpp
        # p7/7.2.protos.cpp
        # p7/7.20.test1.cpp
        # p7/7.20.test10.cpp
        # p7/7.20.test2.cpp
        # p7/7.20.test3.cpp
        # p7/7.20.test4.cpp
        # p7/7.20.test5.cpp
        # p7/7.20.test6.cpp
        # p7/7.20.test7.cpp
        # p7/7.20.test8.2.cpp
        # p7/7.20.test8.cpp
        # p7/7.20.test9.cpp
        # p7/7.3.twoarg.cpp
        # p7/7.4.lotto.cpp
        # p7/7.5.arrfun1.cpp
        # p7/7.6.arrfun2.cpp
        # p7/7.7.arrfun3.cpp
        # p7/7.8.arrfun4.cpp
        # p7/7.9.strgfun.cpp

        # p8/8.1.inline.cpp
        # p8/8.10.left.cpp
        # p8/8.11.funtemp.cpp
        # p8/8.11.funtemp2.cpp
        # p8/8.12.twotemps.cpp
        # p8/8.13.twoswap.cpp
        # p8/8.14.temptempover.cpp
        # p8/8.15.choices.cpp
        # p8/8.16.test1.cpp
        # p8/8.16.test2.cpp
        # p8/8.16.test3.cpp
        # p8/8.16.test4.cpp
        # p8/8.16.test5.cpp
        # p8/8.16.test6.cpp
        # p8/8.16.test7.cpp
        # p8/8.2.firstref.cpp
        # p8/8.3.sceref.cpp
        # p8/8.4.swaps.cpp
        # p8/8.5.cubes.cpp
        # p8/8.6.strtref.cpp
        # p8/8.7.strquote.cpp
        # p8/8.8.filefunc.cpp
        # p8/8.9.left.cpp
        # p8/ep-data.txt

        # p9/9.1/coordin.cpp
        # p9/9.1/coordin.h
        # p9/9.1/main.cpp
        # p9/9.10/9.10.newplace.cpp
        # p9/9.11/9.11.namesp.h
        # p9/9.11/9.12.namesp.cpp
        # p9/9.11/9.13.namessp.cpp
        # p9/9.12.test1/golf.cpp
        # p9/9.12.test1/golf.h
        # p9/9.12.test1/main.cpp
        # p9/9.12.test2/9.12.test2.cpp
        # p9/9.12.test3/test3.cpp
        # p9/9.12.test4/sales.cpp
        # p9/9.12.test4/sales.h
        # p9/9.12.test4/test4.cpp
        # p9/9.2/auto.cpp
        # p9/9.5/9.5.external.cpp
        # p9/9.5/9.6.support.cpp
        # p9/9.7/9.7.twofile1.cpp
        # p9/9.7/9.8.twofile2.cpp
        # p9/9.9/9.9.static.cpp

        # p10/10.1/stock00.cpp
        # p10/10.1/stock00.h
        # p10/10.1/usestock00.cpp
        # p10/10.10/stack.cpp
        # p10/10.10/stack.h
        # p10/10.10/stacker.cpp
        # p10/10.11.test1/account.cpp
        # p10/10.11.test1/account.h
        # p10/10.11.test1/test_account.cpp
        # p10/10.11.test2/main.cpp
        # p10/10.11.test2/person.cpp
        # p10/10.11.test2/person.h
        # p10/10.11.test3/golf.cpp
        # p10/10.11.test3/golf.h
        # p10/10.11.test3/main.cpp
        # p10/10.11.test4/sales.cpp
        # p10/10.11.test4/sales.h
        # p10/10.11.test4/test4.cpp
        # p10/10.11.test5/stack.cpp
        # p10/10.11.test5/stack.h
        # p10/10.11.test5/stacker.cpp
        # p10/10.11.test6/main.cpp
        # p10/10.11.test6/move.cpp
        # p10/10.11.test6/move.h
        # p10/10.11.test7/main.cpp
        # p10/10.11.test7/plorg.cpp
        # p10/10.11.test7/plorg.h
        # p10/10.11.test8/list.cpp
        # p10/10.11.test8/list.h
        # p10/10.11.test8/main.cpp

        # p11/11.1/mytime0.cpp
        # p11/11.1/mytime0.h
        # p11/11.1/usetime0.cpp
        # p11/11.2/mytime1.cpp
        # p11/11.2/mytime1.h
        # p11/11.2/usetime1.cpp
        # p11/11.3/mytime2.cpp
        # p11/11.3/mytime2.h
        # p11/11.3/usetime2.cpp
        # p11/11.4/mytime3.cpp
        # p11/11.4/mytime3.h
        # p11/11.4/usetime3.cpp
        # p11/11.5/randwalk.cpp
        # p11/11.5/vector.cpp
        # p11/11.5/vector.h
        # p11/11.6/stone.cpp
        # p11/11.6/stonewt.cpp
        # p11/11.6/stonewt.h
        # p11/11.6/test_stonewt.cpp
        # p11/11.7/stone.cpp
        # p11/11.7/stonewt.cpp
        # p11/11.7/stonewt.h
        # p11/11.9/test1/randwalk.cpp
        # p11/11.9/test1/randwalk.txt
        # p11/11.9/test1/vector.cpp
        # p11/11.9/test1/vector.h
        # p11/11.9/test2/randwalk.cpp
        # p11/11.9/test2/vector.cpp
        # p11/11.9/test2/vector.h
        # p11/11.9/test3/randwalk.cpp
        # p11/11.9/test3/vector.cpp
        # p11/11.9/test3/vector.h
        # p11/11.9/test4/mytime3.cpp
        # p11/11.9/test4/mytime3.h
        # p11/11.9/test4/usetime3.cpp
        # p11/11.9/test5/stone.cpp
        # p11/11.9/test5/stonewt.cpp
        # p11/11.9/test5/stonewt.h
        # p11/11.9/test6/stone.cpp
        # p11/11.9/test6/stonewt.cpp
        # p11/11.9/test6/stonewt.h
        # p11/11.9/test7/complex0.cpp
        # p11/11.9/test7/complex0.h
        # p11/11.9/test7/test_complex0.cpp

        # p12/test1/stringbad.cpp
        # p12/test1/stringbad.h
        # p12/test1/vegnews.cpp
        # p12/test10/bank.cpp
        # p12/test10/customer.cpp
        # p12/test10/customer.h
        # p12/test10/queue1.cpp
        # p12/test10/queue1.h
        # p12/test2/saying1.cpp
        # p12/test2/saying2.cpp
        # p12/test2/string1.cpp
        # p12/test2/string1.h
        # p12/test3/placenew1.cpp
        # p12/test4/placenew2.cpp
        # p12/test5/bank.cpp
        # p12/test5/customer.cpp
        # p12/test5/customer.h
        # p12/test5/queue1.cpp
        # p12/test5/queue1.h
        # p12/test6/cow.cpp
        # p12/test6/cow.h
        # p12/test6/testCow.cpp
        # p12/test7/string1.cpp
        # p12/test7/string1.h
        # p12/test7/test1.cpp
        # p12/test8/stock00.cpp
        # p12/test8/stock00.h
        # p12/test8/usestock00.cpp
        # p12/test9/stack0.cpp
        # p12/test9/stack0.h
        # p12/test9/usestack0.cpp

        # p13/test1/ratedtabtenn0.cpp
        # p13/test1/ratedtabtenn0.h
        # p13/test1/tabtenn0.cpp
        # p13/test1/tabtenn0.h
        # p13/test1/usett0.cpp
        # p13/test2/brass.cpp
        # p13/test2/brass.h
        # p13/test2/usebrass1.cpp
        # p13/test2/usebrass2.cpp
        # p13/test3/acctabc.cpp
        # p13/test3/acctabc.h
        # p13/test3/usebrass3.cpp
        # p13/test4/dma.cpp
        # p13/test4/dma.h
        # p13/test4/usedma.cpp
        # p13/test5/cd.cpp
        # p13/test5/cd.h
        # p13/test5/test5.cpp
        # p13/test6/cd.cpp
        # p13/test6/cd.h
        # p13/test6/test5.cpp
        # p13/test7/dma.cpp
        # p13/test7/dma.h
        # p13/test7/usedma.cpp
        # p13/test9/port.cpp
        # p13/test9/port.h
        # p13/test9/testport.cpp

        # p14/test1/student.cpp p14/test1/student.h p14/test1/use_stuc.cpp

        # p14/test2/student.cpp p14/test2/student.h p14/test2/use_stuc.cpp

        # p14/test3/worker0.cpp p14/test3/worker0.h p14/test3/workertest.cpp

        # p14/test4/workermi.cpp p14/test4/workermi.h p14/test4/workmi.cpp

        # p14/test5/stacktem.cpp p14/test5/stacktp.h

        # p14/test6/stackoptr1.cpp p14/test6/stacktp1.cpp p14/test6/stacktp1.h

        # p14/test7/arraytp.h p14/test7/twod.cpp        p14/test8/pairs.cpp

        # p14/test9/tempmemb.cpp        p14/test9/tempmemb2.cpp

        # p14/test10/tempparm.cpp

        # p14/test11/frnd2tmp.cpp p14/test11/hasFriend.h

        # p14/test12/hasFriend.h        p14/test12/useHasFriendT.cpp
        # p14/test13/manyfriend.cpp

        # p14/test14/pairs.h        p14/test14/testwine.cpp        p14/test14/wine.cpp        
        # p14/test14/wine.h       p14/test14/testWine.h

        # p14/test15/testwine.cpp        p14/test15/wine.cpp
        # p14/test15/wine.h       p14/test15/testWine.h

        # p14/test16/queuetp.h  p14/test16/queuetmp.h p14/test16/queuetem.cpp

        # p14/test17/person.h  p14/test17/person.cpp p14/test17/testPerson2.cpp p14/test17/testPerson2.h

        # p14/test18/emp.h p14/test18/test_emp.cpp p14/test18/emp.cpp
        # p14/test18/test_emp.h

        # p15/test1/tv.h  p15/test1/tv.cpp  p15/test1/use_tv.cpp  p15/test1/use_tv.h

        # p15/test2/tvfm.h  p15/test2/tv2.cpp  p15/test2/use_tv2.cpp  p15/test2/use_tv2.h

        # p15/test3/nested.cpp p15/test3/queuetp.h p15/test3/nested.h

        # p15/test4/error.h  p15/test4/error1.cpp
        # p15/test4/error3.cpp  p15/test4/error2.cpp   p15/test4/error4.cpp
        # p15/test4/bad_mean.h p15/test4/error5.cpp p15/test4/newexcp.cpp

        # p15/test5/sales.h    p15/test5/sales.cpp    p15/test5/use_sales.cpp  p15/test5/use_sales.h

        # p15/test6/rtti1.h    p15/test6/rtti1.cpp  p15/test6/rtti2.cpp

        # p15/test7/constcast.h p15/test7/constcast.cpp

        # p15/test8/tv3.cpp p15/test8/tv3.h p15/test8/use_tv3.cpp  p15/test8/use_tv3.h

        # p15/test9/bad_mean2.h p15/test9/error6.h p15/test9/error6.cpp

        # p15/test10/bad_mean3.h p15/test10/error7.h p15/test10/error7.cpp

        # p15/test11/use_sales2.cpp p15/test11/use_sales2.h

        p16/test1/str1.h p16/test1/str1.cpp  p16/test1/str2.cpp p16/test1/hangman.cpp
        p16/test1/str3.cpp

        p16/test2/smrtptrs.cpp   p16/test2/smrtptrs.h p16/test2/fowl.cpp

        main/mainProcess.cpp)
