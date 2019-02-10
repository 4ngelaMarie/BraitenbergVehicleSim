#include "gtest/gtest.h"

#include <iostream>
#include <math.h>
#include <ctime>

#include "date.h"

class DateTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
};

TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  * 
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */
  /* Angela's Tests */
TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between first_day & last_day is not calculated properly";
  
  Date Halloween(1999, 10, 31);
  Date Christmas(1999, 12, 25);
  EXPECT_EQ(Halloween.DaysBetween(Christmas), 55) << "Days between is not calculated properly";
  EXPECT_EQ(Christmas.DaysBetween(Halloween), 55) << "Days between is not calculated properly";
  EXPECT_EQ(Halloween.DaysBetween(Halloween), 0) << "Days between is not calculated properly"; 
  
  Date LeapMarch(2016, 03, 01);
  Date LeapJan(2016, 01, 01);
  EXPECT_EQ(LeapJan.DaysBetween(LeapMarch), 60) << "Leap year not calculated properly"; 
}

TEST_F(DateTest, TodaysDateTest) {
  Date today;       
  std::string expected_out_1 = "2019-02-10";
  testing::internal::CaptureStdout();
  today.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1) << "Today's date not implemented correctly";
}

TEST_F(DateTest, GetDateTests) {
  Date basic(1999, 11, 12);
  EXPECT_EQ(basic.GetDate(), "1999-11-12") << "GetDate output: missing a character";
  EXPECT_EQ(basic.GetUsDate(), "11-12-1999") << "GetUsDate output: missing a character";
  
  EXPECT_EQ(first_day.GetDate(), "2018-09-04") << "GetDate output: missing a character";
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "GetUsDate output: missing a character";
}

TEST_F(DateTest, AddingDaysTests) {
  Date basic(1999, 11, 11);
  Date basicplus = basic + 1;
  
  Date y2k(1999, 12, 31);              
  Date plusone = y2k + 1;
  
  Date leapfeb(2016, 02, 28);
  Date leapplus = leapfeb + 1;
  
  Date nye(2001, 12, 31);              
  Date newyear = nye + 1;
  
  std::string expected_out_0 = "1999-11-12";
  std::string expected_out_1 = "2000-01-01";
  std::string expected_out_2 = "2016-02-29";
  std::string expected_out_3 = "2002-01-01";
  
  testing::internal::CaptureStdout();
  basicplus.PrintDate(false);
  std::string output0 = testing::internal::GetCapturedStdout();
 
  testing::internal::CaptureStdout();
  plusone.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  leapplus.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  newyear.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output0, expected_out_0) << "Adding a day not implemented correctly";
  EXPECT_EQ(output1, expected_out_1) << "New Century: Adding a day not implemented correctly";
  EXPECT_EQ(output2, expected_out_2) << "Leap Year: Adding a day not implemented correctly";
  EXPECT_EQ(output3, expected_out_3) << "New Year: Adding a day not implemented correctly";
}

TEST_F(DateTest, SubtractingDaysTests) {
  Date basicdate(1999, 11, 11);
  Date minus = basicdate - 1;
	
  Date newcent(2000, 01, 01);         
  Date minusone = newcent - 1;
  
  Date leapmarch(2016, 03, 1);
  Date leapminusone = leapmarch - 1;
  
  Date newyear(2001, 01, 01);
  Date nye = newyear - 1;

  std::string expected_out_0 = "1999-11-10";
  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "2016-02-29";
  std::string expected_out_3 = "2000-12-31"; 
  
  testing::internal::CaptureStdout();
  minus.PrintDate(false);
  std::string output0 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  minusone.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  leapminusone.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  nye.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output0, expected_out_0) << "Subtracting a day not implemented correctly"; 
  EXPECT_EQ(output1, expected_out_1) << "New Century: Subtracting a day not implemented correctly";
  EXPECT_EQ(output2, expected_out_2) << "Leap Year: Subtracting a day not implemented correctly";
  EXPECT_EQ(output3, expected_out_3) << "New Year: Subtracting a day not implemented correctly";
}

TEST_F(DateTest, EpochTests) {
  Date epoch_0(0); 
  Date epoch_1(86400);  //add number of seconds in a day  
  Date epoch_2(-86400);  //subtract number of seconds in a day          
  std::string expected_out_1 = "1970-01-01";
  std::string expected_out_2 = "1970-01-02";
  std::string expected_out_3 = "1969-12-31";
  
  testing::internal::CaptureStdout();
  epoch_0.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  epoch_1.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  epoch_2.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1) << "Epoch not implemented correctly";
  EXPECT_EQ(output2, expected_out_2) << "Epoch not implemented correctly";
  EXPECT_EQ(output3, expected_out_3) << "Epoch not implemented correctly";
}

TEST_F(DateTest, LeadingZerosTests) {
  Date january(1999, 01, 30);      //leading zero in month           
  Date thefirst(2018, 12, 01);     //leading zeros in day
  Date longtimeago(18, 12, 30);     //leading zeros in year
  
  std::string expected_out_1 = "1999-01-30";
  std::string expected_out_2 = "2018-12-01";
  std::string expected_out_3 = "18-12-30";
  
  testing::internal::CaptureStdout();
  january.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  thefirst.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  longtimeago.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  
  EXPECT_EQ(output1, expected_out_1) << "Leading zero in month not implemented.";
  EXPECT_EQ(output2, expected_out_2)<< "Leading zero in day not implemented.";
  EXPECT_EQ(output3, expected_out_3)<< "Year not implemented correctly.";
}
/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
