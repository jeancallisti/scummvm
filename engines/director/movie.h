/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef DIRECTOR_MOVIE_H
#define DIRECTOR_MOVIE_H

namespace Common {
class ReadStreamEndian;
class SeekableSubReadStreamEndian;
}

namespace Director {

class Archive;
class Cast;
struct CastMemberInfo;
class CastMember;
class DirectorEngine;
class Lingo;

class Movie {
public:
	Movie(DirectorEngine *vm);
	~Movie();

	static Common::Rect readRect(Common::ReadStreamEndian &stream);
	static Common::Array<Common::String> loadStrings(Common::SeekableSubReadStreamEndian &stream, uint32 &entryType, bool hasHeader = true);

	bool loadArchive();
	void setArchive(Archive *archive);
	Archive *getArchive() const { return _movieArchive; };
	Common::String getMacName() const { return _macName; }
	Cast *getCast() { return _cast; }
	Cast *getSharedCast() { return _sharedCast; }
	Score *getScore() { return _score; }

	void clearSharedCast();
	void loadSharedCastsFrom(Common::String filename);

	CastMember *getCastMember(int castId);
	const Stxt *getStxt(int castId);

private:
	void loadFileInfo(Common::SeekableSubReadStreamEndian &stream);

public:
	Archive *_movieArchive;
	Common::Rect _movieRect;
	uint16 _currentMouseDownSpriteId;
	uint16 _currentClickOnSpriteId;
	uint32 _lastEventTime;
	uint32 _lastRollTime;
	uint32 _lastClickTime;
	uint32 _lastKeyTime;
	uint32 _lastTimerReset;
	uint16 _stageColor;
	Cast *_sharedCast;

private:
	DirectorEngine *_vm;
	Lingo *_lingo;
	Cast *_cast;
	Score *_score;

	uint32 _flags;

	Common::String _macName;
	Common::String _createdBy;
	Common::String _changedBy;
	Common::String _script;
	Common::String _directory;
};

} // End of namespace Director

#endif
