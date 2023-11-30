#include <catch2/catch.hpp>
#include "../src/include/AdventDay.h"
#include "../src/AdventFactory.h"

class TestSuiteDay : public AdventDay {
public:
    [[nodiscard]] int mainPartOne() override {
        return EXIT_SUCCESS;
    }

    [[nodiscard]] bool isTestSuiteDay() const {
        return true;
    }

    [[nodiscard]] std::vector<std::string> getArgs() const {
        return args;
    }
};

TEST_CASE("Registry exists", "[registry]") {
    AdventFactory f;
}

TEST_CASE("Registry can add an AdventDay", "[registry]") {
    AdventFactory f;
    f.registerDay("testsuite", []() { return static_cast<AdventDay*>(new TestSuiteDay()); });
}

TEST_CASE("Registry can turn argc + argv into vector of strings", "[registry]") {
    const char* argv[] = {"advent", "testsuite"};
    const auto vArgs = AdventFactory::getArgumentVector(2, argv);
    REQUIRE(vArgs.size() == 2);
    REQUIRE(vArgs[0] == "advent");
    REQUIRE(vArgs[1] == "testsuite");

    SECTION("Null case") {
        const auto vArgsNull = AdventFactory::getArgumentVector(0, nullptr);
        REQUIRE(vArgsNull.empty());
    }
}

TEST_CASE("Registry can retrieve an AdventDay", "[registry]") {
    AdventFactory f;
    f.registerDay("testsuite", []() { return static_cast<AdventDay*>(new TestSuiteDay()); });
    const char* argv[] = {"advent", "testsuite"};
    auto day = f.createDay(2, argv);
    REQUIRE( day != nullptr );
    auto testDay = dynamic_cast<TestSuiteDay*>(day);
    REQUIRE(testDay->isTestSuiteDay());
    delete testDay;
}

TEST_CASE("Registry returns nullptr if day is not registered", "[registry]") {
    AdventFactory f;
    const char* argv[] = {"advent", "testsuite"};
    auto day = f.createDay(2, argv);
    REQUIRE(day == nullptr);
}

TEST_CASE("Registry throws an error if less than 2 parameters are supplied", "[registry]") {
    AdventFactory f;
    const char* argv[] = {"advent"};
    REQUIRE_THROWS(f.createDay(1, argv));
    REQUIRE_THROWS(f.createDay(0, nullptr));
}

TEST_CASE("Registry can fetch all registered modules", "[registry]") {
    AdventFactory f;
    REQUIRE(f.getAvailableDays().empty());

    SECTION("Non-null case") {
        f.registerDay("testsuite", []() { return static_cast<AdventDay *>(new TestSuiteDay()); });
        f.registerDay("testsuite2", []() { return static_cast<AdventDay *>(new TestSuiteDay()); });
        REQUIRE(f.getAvailableDays().size() == 2);
    }
}

TEST_CASE("Registry sets args properly on days", "[registry]") {
    AdventFactory f;
    f.registerDay("testsuite", []() { return static_cast<AdventDay*>(new TestSuiteDay()); });
    const char* argv[] = {"advent", "testsuite", "potato"};
    auto testDay = dynamic_cast<TestSuiteDay*>(f.createDay(3, argv));
    REQUIRE(testDay->getArgs().size() == 1);
    REQUIRE(testDay->getArgs()[0] == "potato");
}

std::vector<std::string> getPart2Args(AdventFactory& f, const char* name) {
    const char* argv[] = {"advent", "testsuite", name};
    auto testDay = dynamic_cast<TestSuiteDay*>(f.createDay(3, argv));
    return testDay->getArgs();
}

TEST_CASE("Registry removes the part2 flag from args automatically", "[registry]") {
    AdventFactory f;
    f.registerDay("testsuite", []() { return static_cast<AdventDay*>(new TestSuiteDay()); });

    SECTION("part2") {
        REQUIRE(getPart2Args(f, "part2").empty());
    }

    SECTION("parttwo") {
        REQUIRE(getPart2Args(f, "parttwo").empty());
    }

    SECTION("--part2") {
        REQUIRE(getPart2Args(f, "--part2").empty());

    }

    SECTION("--parttwo") {
        REQUIRE(getPart2Args(f, "--parttwo").empty());
    }
}
