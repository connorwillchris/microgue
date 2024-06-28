--[[ Global namespace for interfacing with Microgue. ]]
local Microgue = {}

--[[ Mod class. Only used for reference. ]]
---@class Mod
---@field x integer
local Mod = {}

--[[ Registers a mod with the given name. Two mods cannot exist with the same name. ]]
---@param name string
---@param mod Mod
Microgue.register_mod = function(name, mod) end
