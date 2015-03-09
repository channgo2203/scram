#include <gtest/gtest.h>

#include "risk_analysis_tests.h"

// Benchmark Tests for  fault tree from OpenFTA.
TEST_F(RiskAnalysisTest, ThreeMotor) {
  std::string tree_input = "./share/scram/input/benchmark/three_motor.xml";
  std::set<std::string> cut_set;
  std::set< std::set<std::string> > mcs;  // For expected min cut sets.
  std::string T3 = "t3";
  std::string S1 = "s1";
  std::string T4 = "t4";
  std::string T1 = "t1";
  std::string K2 = "k2";
  std::string T2 = "t2";
  std::string K5 = "k5";
  std::string K1 = "k1";
  std::string KT1inc = "kt1inc";
  std::string KT2inc = "kt2inc";
  std::string KT3inc = "kt3inc";
  std::string T1inc = "t1inc";
  std::string T2inc = "t2inc";
  std::string T3inc = "t3inc";
  std::string T4inc = "t4inc";

  // Adjust settings for number of sums.
  ran->AddSettings(settings.probability_analysis(true).num_sums(3));
  ASSERT_NO_THROW(ran->ProcessInput(tree_input));
  ASSERT_NO_THROW(ran->Analyze());
  EXPECT_NEAR(0.0211538, p_total(), 1e-5);
  // Minimal cut set check.
  // Order 1
  cut_set.insert(K5);
  mcs.insert(cut_set);
  cut_set.clear();

  // Order 2
  cut_set.insert(S1);
  cut_set.insert(T2);
  mcs.insert(cut_set);
  cut_set.clear();

  cut_set.insert(K1);
  cut_set.insert(T2);
  mcs.insert(cut_set);
  cut_set.clear();

  cut_set.insert(T1inc);
  cut_set.insert(T2);
  mcs.insert(cut_set);
  cut_set.clear();

  // Order 3
  // Order 4
  cut_set.insert(T2);
  cut_set.insert(T2inc);
  cut_set.insert(T3inc);
  cut_set.insert(T4inc);
  mcs.insert(cut_set);
  cut_set.clear();

  cut_set.insert(KT3inc);
  cut_set.insert(T2);
  cut_set.insert(T2inc);
  cut_set.insert(T3inc);
  mcs.insert(cut_set);
  cut_set.clear();

  cut_set.insert(KT2inc);
  cut_set.insert(T2);
  cut_set.insert(T2inc);
  cut_set.insert(T4inc);
  mcs.insert(cut_set);
  cut_set.clear();

  cut_set.insert(KT2inc);
  cut_set.insert(KT3inc);
  cut_set.insert(T2);
  cut_set.insert(T2inc);
  mcs.insert(cut_set);
  cut_set.clear();

  cut_set.insert(KT1inc);
  cut_set.insert(T2);
  cut_set.insert(T3inc);
  cut_set.insert(T4inc);
  mcs.insert(cut_set);
  cut_set.clear();

  cut_set.insert(KT1inc);
  cut_set.insert(KT3inc);
  cut_set.insert(T2);
  cut_set.insert(T3inc);
  mcs.insert(cut_set);
  cut_set.clear();

  cut_set.insert(KT1inc);
  cut_set.insert(KT2inc);
  cut_set.insert(T2);
  cut_set.insert(T4inc);
  mcs.insert(cut_set);
  cut_set.clear();

  cut_set.insert(KT1inc);
  cut_set.insert(KT2inc);
  cut_set.insert(KT3inc);
  cut_set.insert(T2);
  mcs.insert(cut_set);
  cut_set.clear();

  EXPECT_EQ(12, min_cut_sets().size());
  EXPECT_EQ(mcs, min_cut_sets());
}
