#!/bin/sh

cleos()
{
  docker exec -it eosio /opt/eosio/bin/cleos --url http://127.0.0.1:7777 --wallet-url http://127.0.0.1:5555 "$@"
}

eosio-cpp -abigen -I include -o addressbook.wasm addressbook.cc && \
docker cp ./addressbook.wasm eosio:/contracts/addressbook/addressbook.wasm && \
docker cp ./addressbook.abi eosio:/contracts/addressbook/addressbook.abi && \
cleos set contract addressbook /contracts/addressbook && \
cleos push action addressbook upsert '["alice", "alice", 1990, "shanghai"]' -p alice@active && \
cleos push action addressbook upsert '["bob", "bob", 1970, "hongkong"]' -p bob@active && \
cleos get table addressbook addressbook people -k alice

#cleos push action addressbook erase '["bob"]' -p bob@active
