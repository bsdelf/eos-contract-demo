#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>

using namespace eosio;

class [[eosio::contract]] addressbook: public eosio::contract {

public:
  using contract::contract;

  [[eosio::action]]
  void upsert(name user, std::string name, uint32_t brith, std::string city) {
    require_auth( user );
    const auto ops = [&](auto& row) {
       row.key = user;
       row.name = name;
       row.brith = brith;
       row.city = city;
    };
    address_index addresses(_self, _self.value);
    auto iterator = addresses.find( user.value );
    if (iterator == addresses.end()) {
      addresses.emplace(user, ops);
    } else {
      addresses.modify(iterator, user, ops);
    }
  }

  [[eosio::action]]
  void erase(name user){
    require_auth(user);
    address_index addresses(_self, _self.value);
    auto iterator = addresses.find( user.value );
    eosio_assert(iterator != addresses.end(), "Record does not exist");
    addresses.erase(iterator);
  }

private:
  struct [[eosio::table]] person {
    name key;
    std::string name;
    uint32_t brith;
    std::string city;
    uint64_t primary_key() const { return key.value; }
  };

  using address_index = eosio::multi_index<"people"_n, person>;
};

EOSIO_DISPATCH( addressbook, (upsert)(erase) )
