#include<templates/init>

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
ll rng() { return uniform_int_distribution<ll>(0, INT64_MAX)(gen); }
